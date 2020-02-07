# jquery 动画

    <div id='div1'></div>
    <div id='div2'></div>
    $(function(){
        $('#div1').hover(function(){//移入
            $('#div2').hide();
        },function(){//移出
            $('#div2').show();
        });
    })

* hide(arg1, arg2) show(arg1, arg2) 动画效果是左上角的缩放
* slideDown(arg1, arg2) slideUp(arg1, arg2) 卷帘门效果
* fadeIn(arg1, arg2) fadeOut(arg1, arg2) 淡入淡出效果 透明度0<->100
* fadeTo(arg1, arg3, arg2) arg2 小数形式的透明度

    

        arg1: 动画时长
        arg2: 动画结束回调函数

### animate()

        
        linear 线性
        swing 慢快慢

        $('div').click(function(){
            $(this).animate({
                width: 300,
                height: 300
            }, 4000, 'linear');
            $(that).animate({
                width: 300,
                height: 300
            }, 4000, 'swing');
        })

    更多动画使用jquery-ui 基本弃用。。。。。

### stop() 停止动画

* $(this).stop(); 

            
        stop the first animation, others continue

* $(this).stop(true); 

        
        stop all animations

* $(this).stop(true, true); 

        
        stop all animations and current go to the end

* $(this).finish(); 

        stop all animations and all go to the end

### delay(1000)

    $('div').click(function(){
        $(this).stop(true).animate().delay(1000).animate();
    });

***

#### tip 

    call stop(true) before animate to stop all animations pushed

    $('div').click(function(){
        $(this).stop(true).animate({
            width: 300,
            height: 300
        }, 4000, 'linear');
        $(that).stop(true).animate({
            width: 300,
            height: 300
        }, 4000, 'swing');
    });

***

