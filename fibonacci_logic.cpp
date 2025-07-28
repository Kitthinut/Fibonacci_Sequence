#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = acos(-1);

vector<unsigned long long> fibonacci(unsigned int n)
{
    vector<unsigned long long> seq;
    if (n >= 1)
        seq.push_back(0);
    if (n >= 2)
        seq.push_back(1);
    for (unsigned int i = 2; i < n; i++)
    {
        seq.push_back(seq[i - 1] + seq[i - 2]);
    }
    return seq;
}

struct Point
{
    double x;
    double y;
};

int main()
{
    unsigned int n;
    cout << "Enter number of Fibonacci terms : ";
    cin >> n;

    if (n == 0)
    {
        cout << "No terms to plot." << endl;
        return 0;
    }

    // Constants for spiral
    double a = 2.0;
    double phi = (1.0 + sqrt(5.0)) / 2.0;
    double goldenAngle = PI * (3.0 - sqrt(5.0)); // ~2.39996 radians
    double b = log(phi) / goldenAngle;           // ~0.30635

    // Generate Fibonacci sequence
    vector<unsigned long long> fib = fibonacci(n);

    // Calculate unscaled spiral points (centered at 0,0)
    vector<Point> points;
    double maxX = 0.0, maxY = 0.0;
    for (unsigned int i = 0; i < n; i++)
    {
        double theta = i * goldenAngle;
        double r = a * exp(b * theta);
        double x = r * cos(theta);
        double y = r * sin(theta);
        points.push_back({x, y});

        if (abs(x) > maxX)
            maxX = abs(x);
        if (abs(y) > maxY)
            maxY = abs(y);
    }

    // Define bounding box (e.g. screen size)
    const double width = 1920.0;
    const double height = 1080.0;
    const double padding = 60.0;

    // Calculate scale factor to fit spiral inside bounding box with padding
    double scaleX = (width / 2.0 - padding) / maxX;
    double scaleY = (height / 2.0 - padding) / maxY;
    double scale = (scaleX < scaleY) ? scaleX : scaleY;

    cout << fixed << setprecision(2);
    cout << "\nScaled Fibonacci Spiral Coordinates (centered at 0,0):\n";
    cout << "Index | Fibonacci |     X     |     Y\n";
    cout << "----------------------------------------\n";

    // Print scaled points
    for (unsigned int i = 0; i < n; i++)
    {
        double x_scaled = points[i].x * scale;
        double y_scaled = points[i].y * scale;
        cout << setw(5) << i << " | "
             << setw(9) << fib[i] << " | "
             << setw(8) << x_scaled << " | "
             << setw(8) << y_scaled << "\n";
    }

    cout << "\nScale factor applied: " << scale << endl;
    cout << "Bounding box used: width=" << width << ", height=" << height << ", padding=" << padding << "\n";

    return 0;
}
