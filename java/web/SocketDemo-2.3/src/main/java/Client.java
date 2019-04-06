import javax.swing.*;
import java.io.*;
import java.net.Inet4Address;
import java.net.InetSocketAddress;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket();
        // 超时时间
        socket.setSoTimeout(3000);

        // 链接本地, 端口2000, 超时时间3000
        socket.connect(new InetSocketAddress(Inet4Address.getLocalHost(), 2000), 3000);

        System.out.println("已连接！");
        System.out.println("服务器信息：" + socket.getLocalAddress() + " " + socket.getLocalPort());
        System.out.println("服务器信息：" + socket.getInetAddress() + " " + socket.getPort());

        try {
            todo(socket);
        } catch (Exception e) {
            System.out.println("\n异常，关闭\n");
        }

        socket.close();;
        System.out.println("客户端已退出");
    }

    private static void todo(Socket client) throws IOException {
        InputStream in = System.in;
        // 输入流
        BufferedReader input = new BufferedReader(new InputStreamReader(in));

        // 得到输出流并转换为打印流
        OutputStream outputStream = client.getOutputStream();
        PrintStream socketPrintStream = new PrintStream(outputStream);

        // 得到服务器返回
        InputStream inputStream = client.getInputStream();
        BufferedReader socketBufferdReader = new BufferedReader(new InputStreamReader(inputStream));

        boolean flag = true;
        do {
            // 输入流读取
            String str = input.readLine();
            socketPrintStream.println(str);

            // 服务器读取
            String echo = socketBufferdReader.readLine();
            if ("bye".equalsIgnoreCase(echo)) {
                flag = false;
            } else {
                System.out.println(echo);
            }
        }while (flag);

        // 释放资源
        socketBufferdReader.close();
        socketPrintStream.close();
        inputStream.close();
    }
}
