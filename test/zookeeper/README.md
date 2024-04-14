# 安装zookeeper C API

```shell

tar zxvf zookeeper-3.4.10.tar.gz

cd zookeeper-3.4.10

cd src/c

./configure

make

make install

```

如果make失败, 找到makefile的548行, 将`AM_CFLAGS = -Wall -Werror`改为`AM_CFLAGS = -Wall`


头文件安装到: /usr/local/lib/
```
ls /usr/local/lib/ -l | grep zook
```

库文件安装到: /usr/local/include/zookeeper/
```
ls /usr/local/include/zookeeper/
```