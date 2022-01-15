#include<iostream>
#include<vector>
using namespace std;
struct Point{
    int x, y;
};
int orientation(Point p, Point r, Point q){
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if(val==0) return 0;
    return (val>0)?1:2; //clockwise or anticlockwise
}
void convexHull(Point pts[], int n){
    if(n<3) return;
    vector<Point> hull;
    int l = 0;
    for(int i=1; i<n; i++)
        if(pts[i].x<pts[l].x)
            l = i;
    int p = l, q;
    do{
        hull.push_back(pts[p]);
        q = (p+1)%n;
        for(int i=0; i<n; i++){
            if(orientation(pts[p], pts[q], pts[i])==2)
                q = i;
        }
        p = q;
    }while(p!=l);
    for(int i=0; i<hull.size(); i++)
        cout<<"("<<hull[i].x<<", "<<hull[i].y<<")"<<endl;
}
int main(){
    Point pts[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHull(pts, 7);
}