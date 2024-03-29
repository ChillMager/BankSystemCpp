package demoSocketUDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class ClientUDP2 {
    public static void main(String[] args) throws Exception {
        System.out.println("----------客户端启动----------");
        DatagramSocket sunnan = new DatagramSocket(5438); //客户端sunnan

        //数据bytes
        while (true) {
            Scanner sc = new Scanner(System.in);
            String data = sc.nextLine();
            byte[] bytes = data.getBytes();

            if("exit".equals(data)){
                System.out.println("发送完毕！！！");
                sunnan.close();
                break;
            }
            //byte[] bytes = "你在哪？？？".getBytes();
            //盘子packe1
            DatagramPacket panzi_send = new DatagramPacket(bytes,bytes.length, InetAddress.getLocalHost(),6666);

            sunnan.send(panzi_send);
        }
        //System.out.println("发送完毕！！！");
        //sunnan.close();


    }
}
