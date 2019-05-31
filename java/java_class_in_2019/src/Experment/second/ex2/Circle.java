package Experment.second.ex2;

public class Circle implements Shape {

    private double area = 0, r = 0;

    public Circle(double r) {
        this.r = r;
    }

    private void cacuArea() {
        area = r * r * Math.PI;
    }

    @Override
    public double Area() {
        cacuArea();
        return area;
    }
}
