#include <iostream>

class Point {
    private:
        static int count;
        int size;
        int *x_array, *y_array;
    public:
        Point();
        Point(int x_val[], int y_val[]);
        friend std::ostream& operator <<(std::ostream& output_stream, Point& p) {
            output_stream << "The point's coordinates are: " << p.x_array[0] << " (x-axis), " << p.y_array[0] << " (y-axis)." << std::endl;
            return output_stream;
        }
        Point(Point& p_copy) {
            size = p_copy.size;
            x_array = new int[p_copy.size];
            y_array = new int[p_copy.size];
            x_array[0] = p_copy.x_array[0];
            y_array[0] = p_copy.y_array[0];
        }

        Point& operator =(Point& p_copy){
            size = p_copy.size;
            x_array = new int[p_copy.size];
            y_array = new int[p_copy.size];
            x_array[0] = p_copy.x_array[0];
            y_array[0] = p_copy.y_array[0];
            return *this;
        }

        ~Point() {
            delete[] x_array;
            delete[] y_array;
            x_array = nullptr;
            y_array = nullptr;
        }

        void alterPoint() {
            x_array[0] += 5;
            y_array[0] -= 2;
        }

        friend std::istream& operator >>(std::istream& input_stream, Point& p) {
            input_stream >> p.x_array[0] >> p.y_array[0];
            return input_stream;
        }
};

int Point::count = 0;

Point::Point() {
    count++;
    size = 1;
    x_array = new int[size];
    y_array = new int[size];
}

int main() {
    Point p1;
    std::cin >> p1;
    std::cout << p1;
    Point p2(p1);
    std::cout << p2;
    Point p3 = p1;
    p3.alterPoint();
    std::cout << p3;
    std::cout << p1;
    return 0;
}