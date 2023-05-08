#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
#include <algorithm>

using namespace std;

const int MAX = 10000;
const int MIN = 0;

struct Point{
        float Xcord;
        float Ycord;
        float Zcord;
};

int main(int argc, char *argv[])
{
    
    int total_points = atoi(argv[2]), counter =0, var2, seed;
    float x1, x2, y1, y2, z1, z2, most=0.000, least=10000000.000, dist;

    seed = atoi(argv[1]);
    srand(seed);
    vector<Point> space(total_points);

    for(int i= 0; i<total_points; i++)
    {
        space[i].Xcord = (MAX - MIN) * ((float)rand()/RAND_MAX) + MIN;
        space[i].Ycord = (MAX - MIN) * ((float)rand()/RAND_MAX) + MIN;
        space[i].Zcord = (MAX - MIN) * ((float)rand()/RAND_MAX) + MIN;
    
        for (int i=counter; i< total_points-1; i++)
        {
            space[counter].Xcord = x1;
            space[counter].Ycord = y1;
            space[counter].Zcord = z1;
            var2 = counter+1;

            for (int j=var2; j<total_points; j++)
            {
                space[var2].Xcord = x2;
                space[var2].Ycord = y2;
                space[var2].Zcord = z2;
                dist= sqrt(pow(x2-x1, 2) +
                    pow(y2-y1, 2) +
                    pow(z2-z1, 2));
                if (dist<least)
                    least=dist;
                if (dist>most)
                    most=dist;
                var2 ++;
            }
            counter ++;
        }   
    printf("%.3f %.3f\n", least, most);
}
