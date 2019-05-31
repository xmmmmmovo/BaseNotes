package Experment.second.ex2;

public class Main {
    public static void main(String[] args) {
        Shape []sh = new Shape[]{
            new Circle(12),
            new Triangle(112, 2),
            new Square(3)
        };

        for (int i = 0; i < 3; i++) {
            System.out.println(sh[i].Area());
        }
    }
}
