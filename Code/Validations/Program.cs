using static SplashKitSDK.SplashKit;
using static System.Convert;

string line;
double value;

Write("Please enter a number: ");
line = ReadLine();
while (!IsDouble(line))
{
    WriteLine($"Sorry, I cannot convert {line} to a number");
    Write("Please enter a number: ");
    line = ReadLine();
}
value = ToDouble(line);

WriteLine($"Thanks you I got {value}");