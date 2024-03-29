package demoSocketUDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class ServerUDP {
    public static void main(String[] args) throws Exception {
        System.out.println("----------服务端启动----------");
        DatagramSocket server = new DatagramSocket(6666); //参数是端口号

        while (true) {
            byte[] buffer = new byte[1024*64];
            DatagramPacket panzi_receive = new DatagramPacket(buffer,buffer.length);

            server.receive(panzi_receive);
            int panzi_len = panzi_receive.getLength();

            String s = new String(buffer,0,panzi_len);
            System.out.println(panzi_receive.getAddress().getHostName()+":"+s);
            /*System.out.println("客户端ip:  "+panzi_receive.getAddress().getHostAddress());
            System.out.println("客户端port  : "+panzi_receive.getPort());*/
            //System.out.println(s);
            //System.out.println("---------------------------");
        }


    }
}
