bool lde_solver(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
  g = extended_euclid(a, b, x, y);
  if( c % g != 0 ) return false;
  x *= c / g, y *= c / g;
  return true;
}

bool non_negative_lde(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
  if( not lde_solver(a, b, c, x, y, g) ) return false;
  if( x < 0 or y < 0 ) {
    ll dx = b / g, dy = a / g, steps;
    if( x < 0 ) steps = (-x + dx - 1) / dx;
    if( y < 0 ) steps = - (-y + dy - 1) / dy;
    x += steps * dx, y -= steps * dy;
    if( x < 0 or y < 0 ) return false;
  }
  return true;
}

int extended_euclid(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = extended_euclid(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = extended_euclid(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


