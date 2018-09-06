package team.androidlab.finalltrain;

import java.io.*;

public class Test {
    public static void main(String[] args) throws IOException {
        String path = "D:\\demo";
        File file = new File(path);
        if(!file.exists()){
            file.mkdirs();
        }
//        for (int i = 1; i < 11; i++) {
//            String pathTest = path + "\\test"+ i +".txt";
//            File file1 = new File(pathTest);
//            if(!file1.exists()){
//                try {
//                    file1.createNewFile();
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//        }

//        String[] strings = file.list();
//        for (int i = 0; i < strings.length; i++) {
//            System.out.println(strings[i]);
//        }

//        File[] files = file.listFiles();
//        for (int i = 0; i < files.length; i++) {
//            System.out.println(files[i].getName());
//            System.out.println(files[i].getPath());
//        }

//        File[] files1 = file.list(new FilenameFilter() {
//            //@Override
//            public boolean accept(File dir, File name) {
//                if(dir.getName().endsWith(".txt")){
//                    return true;
//                }
//                return false;
//            }
//        });
//
//        for (File s:
//             files1) {
//            System.out.println(s);
//        }


//        for (int i = 0; i < 10; i++) {
//            File fileShow = new File("D:\\demo\\text"+i+".txt");
//                try {
//                    FileOutputStream fileOutputStream = new FileOutputStream(fileShow);
//                    String s = "Android Lab" + i;
//                    byte[] bytes = s.getBytes();
//                    fileOutputStream.write(bytes);
//                    fileOutputStream.close();
//                } catch (java.io.IOException e) {
//                    e.printStackTrace();
//                }
//        }


        File fileShow = new File("D:\\\\demo\\text.txt");
        try {
            FileWriter fileWriter = new FileWriter(fileShow);
            fileWriter.write("asfasdf");
        } catch (IOException e) {
            e.printStackTrace();
        }

        //FileReader fileReader = new FileReader("D:\\demo\\text2.txt");

        file = new File("D:\\demo\\text0.txt");
        try {
            FileInputStream fileInputStream = new FileInputStream(file);
            byte[] bytes = new byte[(int)file.length()];
            fileInputStream.read(bytes);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}