# js 解析 markdown

### 使用ajax的方式从服务器获取数据

### 使用Marked.js解析md的json数据

    <script src="marked.min.js"></script>

    $(document).ready(function(){
        $('#content').html(marked(markdownjsondata));
    });

### 使用highlight.js实现语法高亮

    <script src="hihtlight.js"></script>
    <link href="highlight/styles/rainbow.css" rel="stylesheet">
    <script>
        hljs.initHighlightingOnLoad();
    </script>

