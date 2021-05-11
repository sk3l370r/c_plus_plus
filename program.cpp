#include "splashkit.h"
#include "terminal_user_input.h"
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using namespace std;

//creates a struct called knight data
struct knight_data
{
    string name;
    int age;
    string month;
    string colour;
    vector<string> tools;
};

struct kingdom_data
{
    string name;
    vector<knight_data> knights;
};

//reads the data into the struct
knight_data read_knight()
{
    knight_data result;

    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter age: ");
    result.month = read_string("Enter a birth month: ");
    result.colour = read_string("Enter their favourite colour: ");
    return result;
}

//writes out the knights details to the terminal using information via pass by reference
//updated to include the read out of the tools
void write_knight(const knight_data &knight)
{
    write_line(knight.name + " aged " + to_string(knight.age) + " born in " + knight.month + " whose favourite colour is " + knight.colour);

    for(int i = 0; i < knight.tools.size(); i++)
    {
        write_line(knight.tools[i]);
    }

    return;
}

//creates an enum for the updated knight options
//extended to include the add and delete tools functions
enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_MONTH,
    UPDATE_COLOUR,
    ADD_TOOL,
    DELETE_TOOL,
    FINISH_UPDATE
};

//displays the menu for updating the knight data
//extended to include the add and delete tool update function
knight_update_option read_knight_update_option()
{
    int result;

    write_line("1: Update name");
    write_line("2: Update age");
    write_line("3: Update birth month");
    write_line("4: Update favourite colour");
    write_line("5: Add Tool");
    write_line("6: Delete Tool");
    write_line("7: Finish update");
    result = read_integer("Select option: ");

    return static_cast<knight_update_option>(result - 1);
}

//this procedure takes the tool selected by the user and deletes it from the dynamic array
//It works within Knight data only and is only accessible using the update knight menu
void delete_tool(knight_data &knight, int index)
{
    if ( index >= 0 and index < knight.tools.size() )
    {
        int last_idx;
        last_idx = knight.tools.size() - 1;
        knight.tools[index] = knight.tools[last_idx];
        knight.tools.pop_back();
    }
    
}

//this procedure adds a tool to a knight in a dynamic array
//the user is able to continue adding tools until they press "q" for quit
//Tools are entered as strings, and converted to uppercase
void add_tool(knight_data &knight)
{
    bool finish = false;
    string tool;


    do
    {
        tool = to_uppercase(read_string("Enter tool to add, or Q to finish adding tools: "));
        if(tool == "Q")
        {
            finish = true;
        }
        else 
        {
            knight.tools.push_back(tool);
        }

    } while (finish != true);

    return;
    
}

//This allows the user to select the tool they wish to delete
//If no tools exist, it outputs an error message
//Sends selected tool to be deleted
void select_tool(knight_data &knight)
{
    int j;
    int option;

    if (knight.tools.size() == 0)
    {
        write_line("No tool is found in record");
    }
    else
    {
        
        for(int i = 0; i < knight.tools.size(); i++)
        {
            j=i+1;
            write(to_string(j) + ": ");
            write_line(knight.tools[i]);
        }

        option = read_integer("Select your tool: ");

        delete_tool(knight, option - 1);
    }
    
    return;
}

//Allows the user to select a knight to be updated. 
//Uses kingdom data
//Error checks by ensuring a valid option is entered
int select_knight(const kingdom_data &kingdom)
{
    int option, j;
    bool valid = false;

    for(int i = 0; i < kingdom.knights.size(); i++)
    {
        j=i+1;
        write(to_string(j) + ": ");
        write_knight(kingdom.knights[i]);
    }

    do
    {
        option = read_integer("Select your knight: ");
        

        if (option < 0 or option > kingdom.knights.size())
        {
            write_line("Please enter a valid option");
        }
        else
        {
            valid = true;
        }
    }while(valid != true);

    return option - 1;
}

//procedure which asks the user to enter new values and updates the knight data using information via pass by reference
//updated to include add and delete tools
void update_knight(knight_data &knight)
{
    knight_update_option option;

    do
    {
        write_line();
        write_line("== Update Knight ==");
        write_knight(knight);
        write_line();
        option = read_knight_update_option();

        switch(option)
        {
            case UPDATE_NAME:
                knight.name = read_string("Enter new name: ");
                break;
            case UPDATE_AGE: 
                knight.age = read_integer("Enter new age: ");
                break;
            case UPDATE_MONTH:
                knight.month = read_string("Enter new birth month: ");
                break;
            case UPDATE_COLOUR:
                knight.colour = read_string("Enter new favourite colour: ");
                break;
            case ADD_TOOL:
                add_tool(knight);
                break;
            case DELETE_TOOL:
                select_tool(knight);
                break;
            case FINISH_UPDATE:
                break;
            default:
                write_line("Please select a valid option");
        }

    } while (option != FINISH_UPDATE);
    
}

//Allows a user to add a new knight to the kingdom
void add_knight(kingdom_data &kingdom)
{
    knight_data new_knight;
    new_knight = read_knight();

    kingdom.knights.push_back(new_knight);
}

//outputs kingdom details
void write_kingdom(const kingdom_data &kingdom)
{
    write_line("=================");
    write_line(kingdom.name);
    write_line("==== Knights ====");
    for(int i = 0; i < kingdom.knights.size(); i++)
    {
        write_knight(kingdom.knights[i]);
    }
    write_line("=================");

    return;
}  

//deletes a knight from the kingdom
void delete_knight(kingdom_data &kingdom, int index)
{
    if ( index >= 0 and index < kingdom.knights.size() )
    {
        int last_idx;
        last_idx = kingdom.knights.size() - 1;
        kingdom.knights[index] = kingdom.knights[last_idx];
        kingdom.knights.pop_back();
    }
}

//Asks the user to enter a kingdom name
kingdom_data read_kingdom()
{
    kingdom_data result;
    result.name = read_string("Enter kingdom name: ");
    return result;
}

//Gets the user to select a knight to query and outputs the information for that knight
void query_knight(const kingdom_data &kingdom)
{
    int i;

    i = select_knight(kingdom);
    write_knight(kingdom.knights[i]);
    return;
}

//deletes a knight from the kingdom
void delete_selection(kingdom_data &kingdom)
{
    int i;

    i = select_knight(kingdom);
    if ( i > 0)
    {
        write_knight(kingdom.knights[i]);
    }

    write_line("About to delete...");
    delete_knight(kingdom, i);

    return;
}

//allows the user to select a knight to update from the kingdom data
void mod_knight(kingdom_data &kingdom)
{
    int option;

    option = select_knight(kingdom);

    update_knight(kingdom.knights[option]);

    return;

}

//update kingdom menu 
void update_kingdom(kingdom_data &kingdom)
{
    int option;

    do
    {
        write_line("==== Menu ====");
        write_line("1: Add a Knight");
        write_line("2: Delete a Knight");
        write_line("3: Display Kingdom Details");
        write_line("4: Query a Knight");
        write_line("5: Update a Knight");
        write_line("6: Quit");
        option = read_integer("Please Select an Option: ");

        switch(option)
        {
            case 1:
                add_knight(kingdom);
                break;
            case 2:
                delete_selection(kingdom);
                break;
            case 3:
                write_kingdom(kingdom);
                break;
            case 4:
                query_knight(kingdom);
                break;
            case 5:
                mod_knight(kingdom);
                break;
            case 6:
                break;
            default:
                write_line("Please select a valid option");
        }


    } while (option != 6);

    return;
    
}

int main()
{
    kingdom_data my_kingdom = read_kingdom();
    
    update_kingdom(my_kingdom);

    return 0;
}