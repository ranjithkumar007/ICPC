const ll MAX = 200001;

// note : be careful of indexing
// start, end, l, r must be of same type of array indexing.

// point query and point range
// no lazy
class SegTree {
    ll T[MAX << 2];

    inline ll merge(ll a, ll b) {
        return a + b;
    }

    public:

    void build(ll node, ll start, ll end, vector<ll>&A)
    {
        if (start == end) {
            T[node] = A[start - 1];
        } else {
            ll mid = (start + end) >> 1;
            build(node << 1, start, mid, A);
            build((node << 1) + 1, mid + 1, end, A);
            T[node] = merge(T[node << 1], T[(node << 1) + 1]);
        }
    }

    ll query(ll node, ll start, ll end, ll l)
    {
    	if (start == end)
    		return start;
        ll mid = (start + end) >> 1;
    	if (T[node<<1] <= l) return query((node << 1) + 1, mid + 1, end, l-T[node<<1]);
    	return query(node<<1, start, mid, l);
    }

    void update(ll node, ll start, ll end, ll l, ll val) 
    {
        if (start == end) 
            T[node] = val;
        else {
            ll mid = (start + end) >> 1;
            if (start <= l and l <= mid) update(node << 1, start, mid, l, val);
            else update((node << 1) + 1, mid + 1, end, l, val);
            T[node] = merge(T[node << 1], T[(node << 1) + 1]);
        }
    }
};

// point update, query range, no lazy
class SegTree {
    int T[MAX << 2];
    
    
    inline int merge(int a, int b) {
        return min(a, b);
    }
    
    public:
    
    void build(int node, int start, int end, vector<int>&A)
    {
        if (start == end) {
            T[node] = A[start - 1];
        } else {
            int mid = (start + end) >> 1;
            build(node << 1, start, mid, A);
            build((node << 1) + 1, mid + 1, end, A);
            T[node] = merge(T[node << 1], T[(node << 1) + 1]);
        }
    }
    
    int query(int node, int start, int end, int l, int r)
    {
        if (start > r or end < l or start > end) return INT_MAX;
        if (start >= l and end <= r) return T[node];
        int mid = (start + end) >> 1;
        return merge(query(node << 1, start, mid, l, r), query((node << 1) + 1, mid + 1, end, l, r));
    }
    
    void update(int node, int start, int end, int l, int val) 
    {
        if (start == end) 
            T[node] = val;
        else {
            int mid = (start + end) >> 1;
            if (start <= l and l <= mid) update(node << 1, start, mid, l, val);
            else update((node << 1) + 1, mid + 1, end, l, val);
            T[node] = merge(T[node << 1], T[(node << 1) + 1]);
        }
    }
};
