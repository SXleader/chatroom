# chatroom  
## the chatroom with the epoll   
  
  
### 服务器采用 多进程，i/o复用实现并发，基于epoll开发的即时聊天服务器，客户端采用socket进行进程间通信，分别负责消息的read/write, 并用mysql数据库进行数据存储.

### **环境**  ：Ubuntu 20.04 + gcc + vim + gdb + mysql  

### **说明**  :此聊天室具备客户端和服务端，服务端接受新的客户端链接，并将每个客户端发来的信息发给所有客户端。客户端接受服务端发来的消息，并且可以将信息发送给服务端. 除此之外，还可以通过输入字符串的第一个字符来表示是发送群聊还是单独发送给某人，实现了广播和点对点的通讯。并且用mysql的两个表格进行数据存储。     

### **how to start** : make Server.o make Clinet.o make all   

### **改进** :后续会增加更多功能.      

