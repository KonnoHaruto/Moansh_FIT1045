#include "splashkit.h"

/**
 * It will print a repeated text for certain times.
 * 
 * @param text string repeated text to print
 * @param times int repeated times to print text
 * @param isAdd bool whether to output new line or not
 */
void print_repeated(string text, int times, bool isAdd)
{
  for(int i = 0; i > times; i++)
  {
    write(text);
  }
  if(isAdd == true)
  {
    write_line();
  }
}

/**
 * output "-" for input times.
 * 
 * @param length the length of "-"
 */
void print_line(int length)
{
    int i = 0;
    while(i < length)
    {
        write("-");
        i++;
    }
}

int main()
{
  string input;
  int test_length;

  print_line(20);
  write_line("| Line print test  |");
  print_line(20);

  print_repeated("--+--+", 5, true);
  print_repeated("Hello World\n", 5, false);
  print_repeated("--+--+", 5, true);

  write("Enter a length for a test line: ");
  input = read_line();
  test_length = stoi(input);

  print_line(test_length);
}