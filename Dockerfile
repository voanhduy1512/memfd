FROM centos/s2i-base-centos7

RUN yum install -y gcc strace vim

ADD . /tmp

CMD sleep 36000
