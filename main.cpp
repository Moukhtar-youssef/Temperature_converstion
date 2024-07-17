#include <iostream>
#include <string>
#include <format>
using namespace std;

string Input_temperature_type;
string Output_temperature_type;
double input_temperature;
double output_temperature;
char x;
string final;
void taking_in_the_temp();


void convert() {
    if ( Input_temperature_type == "c" && Output_temperature_type == "f") {
        output_temperature = (input_temperature * 9/5) + 32;
        return;
    }
    else if (Input_temperature_type == "c" && Output_temperature_type == "k" ) {
        output_temperature = input_temperature + 273.15;
        return;
    }
    else if (Input_temperature_type == "f" && Output_temperature_type == "c") {
        output_temperature = (input_temperature - 32) * 5/9;
        return;
    }
    else if (Input_temperature_type == "f" && Output_temperature_type == "k") {
        output_temperature = (input_temperature - 32) * 5/9 + 273.15;
        return;
    }
    else if (Input_temperature_type == "k" && Output_temperature_type == "c") {
        output_temperature = input_temperature - 273.15;
        return;
    }
    else {
        output_temperature = (input_temperature - 273.15) * 9/5 + 32;
        return;
    }
}

void check_if_the_type_is_the_same() {
    while (true) {
        if (Input_temperature_type == Output_temperature_type) {
            cout << "You inputed the same scale try using different scales \n";
            taking_in_the_temp();
        }
        else {
            break;
        }
    }
    return;
}

void taking_in_the_temp() {
    cout << "Which temperature scale for the input ? [c] , [f] , [k] :\n";
    cin >> Input_temperature_type;
    for (auto& x : Input_temperature_type) {
        x = tolower(x);
    }
    cout << "What is the temperature :\n";
    cin >> input_temperature;
    cout << "Which temperature scale for the output ? [c] , [f] , [k] :\n";
    cin >> Output_temperature_type;
    for (auto& x : Output_temperature_type) {
        x = tolower(x);
    }
    check_if_the_type_is_the_same();
    convert();
    return;
}

int main() {
    taking_in_the_temp();
    final = format("The converstion of {} {} is {} {}",input_temperature,Input_temperature_type,output_temperature,Output_temperature_type);
    cout << final;
    return 0;
}
