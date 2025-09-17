using static SplashKitSDK.SplashKit;
using static System.Convert;

// bool ready = false;

Write("Enter a number: ");
string line = ReadLine();
int value = ToInt32(line);

bool bigValue = value > 100;

Write("Is that a big value for you? [y/n]: ");
line = ReadLine();

bool bigForUser = (line == "y") || (line == "Y");

bool bigForBoth = bigForUser && bigValue;