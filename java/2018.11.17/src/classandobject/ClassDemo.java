package classandobject;

public class ClassDemo {
    String name = "baqianyue";
    int age = 20;

    public ClassDemo() {
    }

    public ClassDemo(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void show(){
        System.out.println("姓名"  + name + "\n年龄" + age);
    }

//    public static void main(String[] args) {
//        new ClassDemo("抱歉月", 20).show();
//    }
}
