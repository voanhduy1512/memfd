FROM centos/s2i-base-centos7

RUN yum install -y gcc strace vim

ADD . /tmp/test_memfd

RUN gcc /tmp/test_memfd/test.c -o /tmp/test_memfd/test && chmod +x /tmp/test_memfd/test

CMD /tmp/test_memfd/test
