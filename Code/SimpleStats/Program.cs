using static SplashKitSDK.SplashKit;
using static System.Convert;

string line;
double total = 0;
int count = 0;
double value;
double minValue = 0;
double maxValue = 0;
string again;

Write("Welcome to the simple stats calculator:");
WriteLine();

while (true)
{
    Write("Enter value: ");
    line = ReadLine();
    value = ToInt32(line);
    count++;
    total += value;
    if (count == 1)
    {
        minValue = value;
        maxValue = value;
    }
    if (count != 0 && minValue > value)
    {
        minValue = value;
    }
    if (count != 0 && maxValue < value)
    {
        maxValue = value;
    }

    WriteLine($"Count: {count}");
    WriteLine($"Total: {total}");
    WriteLine($"Min: {minValue}");
    WriteLine($"Max: {maxValue}");
    WriteLine($"Average: {total / count}");
    WriteLine();

    Write("Add another value: [y/n] ");
    again = ReadLine();
    if (again != "y")
    {
        WriteLine("I hope you got the information you are after!");
        break;
    }
}
