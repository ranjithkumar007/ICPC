// Rectange intersection
ll intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
	ll x5 = max(x1, x3);
	ll y5 = max(y1, y3);
	ll x6 = min(x2, x4);
	ll y6 = min(y2, y4);

	if (x6 < x5 or y6 < y5) {
		// no overlap
		return 0;
	}
	return (x6-x5) * (y6-y5);
}