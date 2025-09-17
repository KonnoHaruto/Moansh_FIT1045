using static SplashKitSDK.SplashKit;
using static System.Convert;

string line;
int value = 0;

Write("Enter a number: ");
line = ReadLine();


if (LengthOf(line) == 0)
{
    WriteLine("You did not enter anything!");
}

bool validData = IsInteger(line);

if (validData)
{
    value = ToInt32(line);
}
else
{
    WriteLine("Nice try... that is not a number.");
    value = Rnd(1, 1000) - 500;
    WriteLine($"I picked {value} for you!");
}

    value = ToInt32(line);

if (value > 100)
{
    WriteLine("That is larger that I thought");
}
else
{
    WriteLine("Interesting");
}

if (value < 0)
{
    WriteLine("A negative number");
}
else if (value > 0)
{
    WriteLine("A positive number");
}
else
{
    WriteLine("Zero!");
}

WriteLine(" a - say hello");
WriteLine(" b - say bye");
WriteLine(" c - say Ni!");
WriteLine();
Write("Enter option: ");
string line = ReadLine();

switch (line)
{
    case "A":
    case "a":
        WriteLine("Hello");
        break;
    case "B":
    case "b":
        WriteLine("Bye");
        break;
    case "C":
    case "c":
        WriteLine("Ni");
        break;
    default:
        WriteLine("Please chose one of the indicated options.");
        break;
}




