# Linux tool nmap 

#### namp[<扫描类型>... ][<选项>]{<扫描目标说明>}

目标规范:

    可以使用 主机名，Ip地址，网络，等等
        比如: scanme.nmap.org, microsoft.com/24, 192.168.0.1; 10.0.0-255.1-254
    -iL <输入文件名>: 从主机/网络列表中导入
    -iR <num hosts>: choose random targets
    --exclude <主机名1[,主机名2][,主机名3],...>: 排除主机/网络
    --excludefile <排除文件>: 从文件中导入排除列表

主机发现:

    -sL: 简单地列出要扫描的目标
    -sn: 使用ping扫描，禁用端口扫描
    -Pn: 认为所有主机在线 跳过主机发现环节
    -PS/PA/PU/PY[端口列表]: 通过TCP SYN/ACK, UDP 或 SCTP 发现来提供端口
    -PE/PP/PM: ICMP输出,时间戳,网络掩码请求发现,
    -PO[协议列表]: IP协议ping
    -n/-r: 不进行dns解析/总是进行dns解析 默认根据实际情况
    -dns-servers <server[,server2][server3]>: 自定义dns服务器地址
    -system-dns: 使用系统的dns服务器
    -traceroute: 跟踪每一个主机的路由

扫描技术:

    -sS/sT/sA/sW/sM: TCP SYN/Connect()/ACK/Window/Maimon scan
    -sU: UDP 扫描
    -sN/sF/sX: TCP Null, FIN, 和Xmas 扫描
    --scanflags <flags>: 自定义TCP扫描标记
    -sI <zombie host[:探针端口]>: 闲置扫描
    -sY/sZ: SCTP INIT/COOKIE-ECHO 扫描
    -sO: Ip协议扫描
    -b <ftp中继主机>: ftp反弹扫描
    

端口规范和扫描规则:

    -p <端口范围>: 只扫描指定的端口
        例子: -p22 -p1-65535 -p U:53,111,137,T:21-25,80,139,8080,S:9
    --exclude-ports <端口范围>: 从扫描范围中排除指定端口
    -F: 快速模式 比默认模式扫描更少的端口
    -r: 连续扫描端口, 不随机
    -top-ports <数值>: 扫描前几个最常用的端口
    --port-ratio <比>: 扫描更加常用的端口
    

服务/版本检测:

    -sV: 开启探针端口来检测服务或版本信息
    --version-intensity <level>: 从0到9, 代表版本检测强度
    --version-light: 限制到最有可能的版本
    --version-all: 尝试每一个版本可能
    --version-trace: 用于debug, 显示详细的版本检测活动
    

使用脚本检测:

    -sC: 等效于 --script=default
    --script=<Lua 脚本>: Lua脚本是一个用逗号分隔的脚本列表, 脚本文件或者脚本目录
    --script-args=<n1=v1,[n2=v2]> 提供脚本的参数
    --script-args-file=filename: 从文件中读取脚本的参数
    --script-trace: 显示发送和接收的全部数据
    --script-updatedb: 更新脚本数据库
    --script-help=<Lua 脚本>: 显示脚本的帮助信息
    

系统检测:

    -O: 启用系统检测
    --osscan-limit: 限制系统检测的可能目标
    --osscan-guess: 更积极得检测系统
    

超时和性能:

    时间选项的单位是秒, 或者在值后面加上ms s m或者h
    -T<0-5>: 设置计时模板, 时间更长或更短
    --min-hostgroup/max-hostfroup <大小>: 平行主机扫描组的大小
    --min-parallelism/max-parallelism <numprobes>: 探针并行化
    --min-rtt-timeout/max-rtt-timeout/initial-rtt-timeout <time>: 指定探测超时时间
    --max-retries <tries>: 限制端口扫描探针重发的数量
    --host-timeout <time>: 超时放弃主机
    --scan-delay/--max-scan-delay <time>: 调整两个探针的时间间隔
    --min-rate <number>: 每秒发包的最小数量
    --max-rate <number>: 每秒发包的最大数量

防火墙/访问限制的规避和欺骗:

    -f; --mtu <val>: 包分片
    -D <诱饵1[,诱饵2][,诱饵3]>: 伪装一个带有诱饵的扫描
    -S <ip地址>: 恶搞源地址。。。。意思应该是伪装源地址的意思吧
    -e <接口>: 使用特定的接口
    -g/--source-port <端口号>: 使用所给的端口号
    --proxies <url1[,url2][,url3]>: 使用http或者socks4代理
    --data <十六进制字符串>: 向发送的包添加一个十六进制有效载荷
    --data-string <字符串>: 向发送的包添加一个ASCII字符串
    --data-length <数值>: 向发送的包添加一个指定长度的随机数据串
    --ip-options <选项>: 发送带有特定ip选项的包
    --ttl <val>: 设置ip的ttl
    --spoof-mac <mac地址/前缀/厂商名>: 伪装你的MAC地址
    --badsum: 发送带有虚假TCP/UDP/SCTP校验和的包

输出:

    -oN/-oX/-oS/-oG <文件>: 分别为 正常的输出,XML, (-oS没有理解), 图表格式 输出到文件
    -oA <基础文件名>: 一次输出上述三种格式的数据
    -v: 增加冗长的等级 v越多越甚
    -d: 提高debug等级 d越多越甚
    --reason: 显示端口处于特定状态的原因
    --open: 只显示(可能)开放的端口
    --packet-trace: 显示发送和接收的所有包
    --iflist: 用于debug, 输出主机端口和路由
    --append-output: 追加指定的输出文件, 而不是删除(覆盖)指定的输出文件
    --resume <文件名>: 恢复一个中断的扫描任务
    --stylesheet <路径/链接>: XSL 
    --webxml: 从Nmap.org获取更多可移植的xml样式表
    --no-stylesheet: 不使用样式表输出

杂项:

    -6: 启用ipv6扫描
    -A: 同时启用系统检测, 版本检测, 脚本检测, 路由追踪
    --datadir <文件夹目录>: 自定义nmap的数据文件目录
    --send-eth/--send-ip: 使用原始以太网帧或ip数据包发送
    --privileged: 假设用户拥有完整的特权
    --unprivileged: 假设用户缺少原始的socket特权
    -V: 输出版本号
    -h: 输出这个帮助页面

