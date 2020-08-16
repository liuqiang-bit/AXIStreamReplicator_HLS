# AXIStreamReplicator_HLS

> 此模块用于复制流对象，有v1和v2和v2.1三个版本，v1版本方便联合仿真，v2版本联合仿真时间久，且会导致视频卡顿，但资源占用只有v1的一半。v2.1在v2基础上增加了FIFO深度，解决视频卡顿，三个均已上板测试。另外，v2和v2.1版本的IP无需在PS端进行任何配置或初始化。
>

## 一、使用**\source\copyStream_vX\create_project.tcl**复现工程(X指版本号1、2、2.1)

### 1、打开 Vivado HLS Command Prompt工具

<img src="./images/1.png" style="zoom:50%;" />

### 2、定位到下载的文件目录。例如文件下载在目录**C:\Users\GUDONG\Desktop\tcl_test**中，如下图所示。

![](./images/2.png)



<img src="./images/3.png" style="zoom:50%;" />

### 3、输入并运行指令：vivado_hls -f create_project.tcl，等出现如下画面。

![](./images/4.png)

### 4、输入并运行指令：vivado_hls -p copyStream，Vivado HLS软件将自动启动并打开工程。

### 5、进行C仿真、C\RTL联合仿真（联合仿真需将顶层函数中的ap_ctrl_none指令更换为ap_ctrl_hs,否则报错）

### 6. v2版性能参数。

<img src="F:\MyGit\AXIStreamReplicator_HLS\images\5.png" style="zoom:50%;" />

### 7.上板实测。

![](F:\MyGit\AXIStreamReplicator_HLS\images\6.png)