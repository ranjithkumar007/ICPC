int extended_euclid(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
        }
	int x1, y1;
	int g = extended_euclid(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

// ax + by = c has solution if c % gcd(a, b) == 0. 
// to handle negative values of a and b, pass only abs(a) and abs(b), then if a < 0, x *= -1. similar for y.
