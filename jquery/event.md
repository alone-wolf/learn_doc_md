# jquery event

    事件触发和取消详见function.md

* ev

* preventDefault
* stopPropagation

        $(function(){
            $('div').click(function(ev){
                alert('aaa');

                ev.stopPropagation();
            });
            $('a').click(function(ev){
                ev.preventDefault();
                ev.stopPropagation();

                如果要既阻止事件冒泡又阻止默认行为可以用
                return false;
                代替以上两行
            });
        });

* pageX
* which

        鼠标事件: button
            1 左键
            2 滚轮
            3 右键
        keydown: keycode 键码
        keypress: charCode 字符码 区分大小写

        $(window).keydown(function(ev){
            alert(ev.which);
        })

## 实现页面中div拖拽

    $(function(){
        $('div').mousedown(function(ev){
            var offsetX = ev.pageX - $(this).offset().left;
            var offsetY = ev.pageY - $(this).ofset().right;
            var that = this;
            $(document).mousemove(function(ev){
                $(that).css({
                    left: ev.pageX - offsetX;
                    right: ev.pageY - offsetY;
                });
            });
        });

        $(document).mouseup(function(){
            $(document).off('mousemove');
        });
    });

