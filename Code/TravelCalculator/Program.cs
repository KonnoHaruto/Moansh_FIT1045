using static System.Convert;
using static SplashKitSDK.SplashKit;

const int MINUTES_PER_HOUR = 60;

String name;
double distance, minutes, averageSpeed;
double remainingDistance;
double remainingMinutes, totalMinutes;

Write("What is your name: ");
name = ReadLine();

WriteLine();
WriteLine("Hi " + name);
WriteLine();

Write("How far have you travelled so far? Enter km: ");
distance = ToDouble(ReadLine());
Write("How long has it taken? Enter minutes: ");
minutes = ToDouble(ReadLine());
// hours = minutes / MINUTES_PER_HOUR;

averageSpeed = distance / (minutes / MINUTES_PER_HOUR);

WriteLine();
WriteLine($"Your average speed is {averageSpeed} km/h");
WriteLine();

Write("How far do you have to go? Enter km: ");
remainingDistance = ToDouble(ReadLine());

remainingMinutes = remainingDistance / averageSpeed;
totalMinutes = minutes + remainingMinutes;

WriteLine();
WriteLine($"You will take another {remainingMinutes} minutes before you arrive.");
WriteLine($"Total distance will be {distance + remainingDistance} km");
WriteLine($"Total time will be {totalMinutes} minutes");




