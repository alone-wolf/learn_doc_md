# jquery functions

## filter

    过滤 对已经获取到的网页进行过滤

    $('div').filter('.box').css('backgroundColor','orange'); 

## not

    filter的反义词

    $('div').not('.box').css('backgroundColor','orange');

## has

    拥有 判定子节点是否有满足条件的

    $('div').has('.box').css('backgroundColor','orange'); 

***

## prev

    查找当前节点兄弟节点中的上一个节点

## next

    查找当前节点兄弟节点中的下一个节点

***

## find

    查找当前节点下符合条件的子节点
    $('ul').find('li').css();
    $('ul').find('[name=hello]').css();

## index

    获取当前节点在兄弟节点中的下标
    <div>
        <h2></h2>  //0
        <p></p>    //1
        <h3></h3>  //2
    </div>
    $('h3').index();  //2

## eq

    通过下标获取指定的元素节点
    <ul>
        <li></li>  //0
        <li></li>  //1
        <li></li>  //2
        <li></li>  //3
    </ul>
    $('li').eq(3).css();
    ||
    $('li:eq(3)').css();

## attr

    设置修改属性
    <div id='div'></div>
    $('#div').attr('class','a')

    $('#div').attr({
        'class':'a',
        'value':'b'.
        'title':'c'
    });

## width

    获取元素的实际宽度

## innerWidth

    width + padding

## outerWidth

    $('div').outerWidth();
    width + border + padding

    $('div').outerWidth();
    width + border + padding + margin

***
***

    <body>
        <h2></h2>
        <div></div>
        <span></span>
    </body>
    

## insertBefore before

    找到span节点 插入到div前面
    $('span').insertBefore($('div'));

    $('div').before('span');
    div放在span前面

## insertAfter after

    找到h2节点 插入到div后面
    $('h2').insertAfter($('div'));

    $('div').after('h2');
    div放在h2后面

## appendTo appendChild append

    找到h2节点 插入到div内部结尾
    $('h2').appendTo($('div'));

    $('div').append($('h2'));
    div内部结尾处插入h2

## prependTo prepend

    找到h2节点 插入到div内部开头
    $('h2').prependTo($('div'));

    $('div').prepend($('h2'));
    div内部开头插入h2

## remove

    找到div节点 删除
    var node = $('div').remove();
    返回删除的节点
    不会保留原来节点的事件和行为

## detach

    找到div节点 删除
    var node = $('div').remove();
    返回删除的节点
    保留原来节点的事件和行为

## on

* 给一个事件添加一个函数

    
        $('div').on('click',function(){
            alert();
        });

* 同时给多个事件添加一个函数 多个事件空格隔开

        $('div').on('click mouseover',function(){
            alert();
        });

* 给不同的事件添加不同的函数

        $('div').on({
            click:function(){},
            mouseocer:function(){},
            mouseout:function(){}
        });

* 事件委托

        $('div').on('click','#list_con',function(){
            $(this).css();
        });

## off

    取消事件

    var show = function(){};
    $('div').on('click',show());

    $('button').on('click',function(){
        $('div').off('click',show); 取消div上click事件的show函数
        $('div').off('click'); 取消div上click事件的所有函数
        $('div').off(); 取消div上所有事件的所有函数
    });

### text

    标签间文本

### html

    标签间内容

## 创建节点

    $('<li>abc</li>').appendTo($('ul'));
    
    以下代码是向ul结点中插入一内容为 7777 的li标签
    var i = 6;
    $('<li>${i++ * 1111}</li>').appendTo($('ul'));
    

