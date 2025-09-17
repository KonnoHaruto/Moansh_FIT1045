using static System.Console;
using static System.Convert;
int i;

for (i = 0; i < 11; i++)
{
    if (i > 0 && i % 3 == 0)
    {
        i++;
        continue;
    }

    WriteLine(i);
}