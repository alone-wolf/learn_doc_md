# nodejs hexo base operation

## Linux

### install hexo 

    npm install hexo-cli -g

### upgrade hexo

    npm update hexo -g

### add cmd to global

    ln -s /home/node-xx/lib/node_modules/hexo-cli/bin/hexo /usr/local/bin/hexo

### create a folder to contain blog

    hexo init [blog folder]

### run local server

    hexo server = hexo s 会监视文件变动，自动更新
    hexo server -s   -> static mode
    hexo server -p port    -> set port
    hexo server -i 192.168.1.2    -> set listen ip

### write a new blog

    hexo new "blog title" = hexo n "blog title"

    new blog under source/_posts

### add tags

    write line at head in blog file

    tags: [tag1,tag2]

### generate new blog

    hexo generate = hexo g

### clean project

    hexo clean    -> clean cache

### deploy blog

    hexo deploy = hexo d

    install hexo-deployer-git with cmd:
        npm install hexo-deployer-git --save

    edit file _config.yml
    set deploy:
        type: git
        repository: repo_address
        branch: branch_name

### change theme

    clone theme repo and move folder to themes directory

