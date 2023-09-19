#include <iostream>
#include <limits>
#include <cmath>
long double rms;
long double a;
long double b;
long double rate;
using namespace std;
string choice;
int main()
{          
cout << "\n//=~=~=~=~=~=~=~=~=~=~=~\\\\\n";
cout << " > Audacity RMS Leveler <\n";
cout << "\\\\~=~=~=~=~=~=~=~=~=~=~=//\n";
cout << "For use with Measure RMS & Loudness Normalization\n\n";
redo_strength:
cout << "Peak Height Increase/Decrease: Enter a level (1–100).\n";
cout << "50 is probably what you'd want. A decimal point is allowed.\n>> ";
cin >> rate;
if(!cin)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "\n";
goto redo_strength;
}
if (rate < 0 || rate > 99)
{
goto redo_strength;
}
cout << "\n";
redo_rms:
cout << "Paste or type your dB level from Measure RMS and hit Enter.\n"; 
cout << "(Stereo dB level is recommended if available.)\n>> ";
cin >> rms;
if(!cin)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "\n";
goto redo_rms;
}
a = rms + 50 / 100 * rms;
b = a - rms * 50 / 100;
rms = b * 50 / 100 + rate / 8;
round(rms);
rms = rms - 12;
cout << "\nCopy the value below into the Loudness Normalization (RMS) Effect\n";
cout << "to increase/decrease the peak to the target dB.\n" << rms << "\n\n";
cout << "IF THE AUDIO IS IN STEREO, DO NOT NORMALIZE STEREO CHANNELS INDEPENDENTLY.\n\n";
redo_choice:
cout << "[R]edo or [Q]uit?\n";
cout << ">> ";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, choice);
if (choice == "R" || choice == "r")
{
cout << "\n\n";
goto redo_strength;
}
else if (choice == "Q" || choice == "q")
{
cout << "2023, Made By: ZelkinRush\n";
return 0;
}
else
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "\n";
goto redo_choice;
}
}
