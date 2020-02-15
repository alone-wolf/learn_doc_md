# git config

### set and unset proxy
    git config --global http.proxy 'socks5://127.0.0.1:1080'

    git config --global https.proxy 'socks5://127.0.0.1:1080'

    git config --global --unset http.proxy

    git config --global --unset https.proxy

### set username useremail

    git config --global user.name "name"
    git config --global user.email "xx@XXX.com"

    git config user.name
    git config user.email