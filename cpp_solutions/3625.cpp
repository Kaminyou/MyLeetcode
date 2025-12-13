constexpr int bias=1<<11;
class Solution {
public:
    using ll=long long;

    // Pack 2 integers into one  key
    static int pack2(int a, int b) {
        return ((ll)(a+bias)<<16) | (b+bias);
    }

    // Pack 3 integers into one 64-bit key, note |c|<=2e6
    static ll pack3(int a, int b, int c) {
        return ((ll)(a+bias)<<50)|((ll)(b+bias)<<30)|(c+bias*bias);
    }

    // Pack 4 integers into one 64-bit key
    static ll pack4(int a, int b, int c, int d) {
        return ((ll)(a+bias)<<48)|((ll)(b+bias)<<32)|((ll)(c+bias)<<16)|(d+ bias);
    }

    static int countTrapezoids(vector<vector<int>>& points) {
        const int n=points.size();
        const int nn=n*(n-1);

        unordered_map<ll,int> coeff, midPointWslope;
        unordered_map<ll,int> slope, midPoint;

        coeff.reserve(nn);
        slope.reserve(nn);
        midPointWslope.reserve(nn);
        midPoint.reserve(nn);

        int cnt=0;

        for(int i=0; i<n-1; i++) {
            const int x0=points[i][0], y0=points[i][1];
            for(int j=i+1; j< n; j++) {
                const int x1=points[j][0], y1=points[j][1];
                
                // line : ax+by+c=0
                int a=y1-y0;
                int b=x0-x1;
                int c=y0*x1-y1*x0;

                // the 1st nonzero coeff is positive
                if(a==0 && b<0) { b=-b; c=-c; }
                else if(a<0) { a=-a; b=-b; c=-c; }

                // normalize slope and line coefficients
                int gm=gcd(a, b), gc=gcd(gm, c);

                int ab=pack2(a/gm, b/gm);           // slope key
                ll abc=pack3(a/gc, b/gc, c/gc);    // line key

                // 2 segments with same midpoint with different slopes
                // are the cross lines for a parallelgram
                ll midP=pack2(x0+x1, y0+y1);       // midpoint key 
                ll midab=pack4(x0+x1, y0+y1, a/gm, b/gm); //midpoint+slope key

                cnt+=(slope[ab]++)
                    -(coeff[abc]++)
                    -(midPoint[midP]++)// each parallelgram counts twice
                    +(midPointWslope[midab]++);
            }
        }
        return cnt;
    }
};
