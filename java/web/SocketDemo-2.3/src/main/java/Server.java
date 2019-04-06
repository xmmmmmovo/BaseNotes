import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(2000);

        System.out.println("已连接！");
        System.out.println("服务器信息：" + server.getInetAddress() + " " + server.getLocalPort());

        while (true) {
            // 获取
            Socket client = server.accept();
            // 分发
            ClientHandler clientHandler = new ClientHandler(client);
            // 启动
            clientHandler.start();
        }
    }


    private static class ClientHandler extends Thread {
        private Socket socket;
        private boolean flag = true;

        public ClientHandler(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            super.run();
            System.out.println("新客户端连接：" + socket.getInetAddress() + socket.getPort());

            try {
                // 得到打印流，用于数据输出，服务器回送数据使用
                PrintStream socketOutput = new PrintStream(socket.getOutputStream());
                BufferedReader socketInput = new BufferedReader(
                        new InputStreamReader(socket.getInputStream()));

                do {
                    // 客户端拿到数据
                    String str = socketInput.readLine();
                    if ("bye".equalsIgnoreCase(str)) {
                        flag = false;
                        socketOutput.println("bye");
                    } else {
                        System.out.println(str);
                        socketOutput.println("回送" + str.length());
                    }
                } while (flag);

                socketInput.close();
                socketOutput.close();
            } catch (Exception e) {
                System.out.println("异常断开!");
            } finally {
                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }

                System.out.println("客户端已关闭");
            }
        }
    }
}
