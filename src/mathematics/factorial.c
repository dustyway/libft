

unsigned int factorial(unsigned int n)
{
  if (n <= 1)
    return 1;
  else
    return n * factorial(n - 1);
}