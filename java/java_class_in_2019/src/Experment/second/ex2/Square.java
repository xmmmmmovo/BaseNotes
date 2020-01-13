package Experment.second.ex2;

public class Square implements Shape {

    double area = 0, x = 0;

    public Square(double x) {
        this.x = x;
    }

    private void cacuArea() {
        area = x * x;
    }

    @Override
    public double Area() {
        cacuArea();
        return area;
    }
}
