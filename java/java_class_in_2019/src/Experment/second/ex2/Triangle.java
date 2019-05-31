package Experment.second.ex2;

public class Triangle implements Shape {

    double area = 0, board = 0, height = 0;

    public Triangle(double board, double height) {
        this.board = board;
        this.height = height;
    }

    private void cacuArea() {
        area = (board * height) / 2.0;
    }

    @Override
    public double Area() {
        cacuArea();
        return area;
    }
}
