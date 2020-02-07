# python3 文件操作

    需要涉及到 os、shutil
    os.getcwd() get pwd
    os.system() run shell commander
    os.exit() exit current process
    os.popen() run cmd return result in filefd with r

    os.getenv() get environment
    os.putenv() put environment
    os.linesep  win: '\r\n' linux:'\n' mac:'\r'
    os.name  win:'nt' linux/unix:'posix'

    os.rename(old, new) rename
    os.listdir() get all names of files and folder
    os.mkdir() create one folder
    os.makedirs() like shell mkdir -p x/y/z
    os.remove() delete file
    os.removedirs() like shell rmdir -p x/y/z to del folders
    os.mknod('test.txt') create a blank file

    

    os.stat('static/js/js.js') get file attr
    os.chmod(path,mode)  BIANTAI
    os.path.isfile('static/js.js') judge if file
    os.path.isdir('static/jquery/js') judge if folder
    os.path.isabs() judge if path abs
    os.path.exists() judge if path exists
    os.path.split() split path and filename
    os.path.splitext() get file.ext
    os.path.dirname() get path
    os.path.basename() get filename
    os.path.getsize() get size of file

    filefd = open('file',M)  M:

    

| Character |                         Meaning                         |
|:---------:|:-------------------------------------------------------:|
|    'r'    |               open for reading (default)                |
|    'w'    |       open for writing, truncating the file first       |
|    'x'    | open for exclusive creation, failing if the file exists |
|    'a'    | open for appending to the end of the file, if it exists |
|    'b'    |                       binary mode                       |
|    't'    |                   text mode (default)                   |
|    '+'    |         open for updating (reading and writing)         |
