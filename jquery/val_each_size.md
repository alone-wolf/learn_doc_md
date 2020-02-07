# jquery val each size

## val

    jquery只能取第一个满足条件的值
    $('input').val();

    jquery赋值是个批量操作 val attr html都是这样
    $('input').val('hello world!');
    上述代码会为所有input标签赋值

## each

    $('input').each(function(index,item){
        $(item).html(inex);
    });

## size length

    获取元素的个数
    $('input').size();
    $('input').length(); 这个length是jquery中的函数

