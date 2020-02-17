var re; // 提醒查看的定时器
var onlyDeleteResouce = !!Number('0'); // 允许删除资源而不回收经验
var userPermissionDeleteEveryRes = !!Number('0'); // 删除任何资源的权限
var createrId = '73371488-F37F-543E-81C3-97F63DC345C8'; // 班课创建者
var userId = '8D305132-C2FA-11E8-AA22-7CD30AD36C02';
var userPermissionOther = !!Number('0');
var myPlayerIsloaded = false;
var clazzcourseId = "432F3210-2FA6-11EA-BA85-506B4B4A8386";
var resListUrl = "https://www.mosoteach.cn/web/index.php?c=res&m=index&clazz_course_id=432F3210-2FA6-11EA-BA85-506B4B4A8386";
var uploadFileError = "";
var manualOrderGroupExpandStatusCache = {}; // 手动调序时，分组展开收起状态临时记录。点击保存时再进行保存
var dataIsDrag = false;

/**
 * 设置时间选择期的默认时间
 * param targetDate String 'yyyy-MM-DD' 日期
 * param targetTime String 'HH:mm'  时间
 */
var setDefaultDateTime = function (targetDate, targetTime) {
    if (targetDate && targetTime) {
        $('#release-date').datebox('setValue', targetDate);
        $('#set-date').html(targetDate);
    } else {
        var t = new Date();
        var tomorrow = new Date(t.getTime() + 86400000);
        var r_year = tomorrow.getFullYear();
        var r_month = tomorrow.getMonth() + 1;
        var r_date = tomorrow.getDate();
        $('#release-date').datebox('setValue', r_year + '-' + r_month + '-' + r_date);
        $('#set-date').html(r_year + '-' + r_month + '-' + r_date);
    }
    // 加载小时、分钟列表
    $('#release-hours').combobox('loadData', easyuiReloadHours($('#release-date')));
    var selectedHour = $('#release-hours').combobox('getValue');
    $('#release-minutes').combobox('loadData', easyuiReloadMinutes($('#release-date'), selectedHour));

    if (targetTime) {
        $('#set-time').html(targetTime);

        var targetHour = targetTime.split(':')[0];
        $('#release-hours').combobox('setValue', targetHour);
        var targetMinite = targetTime.split(':')[1];
        $('#release-minutes').combobox('setValue', targetMinite);
    } else {
        $('#set-time').html('08:00:00');
        $('#release-hours').combobox('setValue', '08');
        $('#release-minutes').combobox('setValue', '00');
    }
}
// 资源分组的展开收起状态
var resGroupExpandStatus = {
    data: {},
    switch: function (groupId) {
        this.data[clazzcourseId][groupId] = !this.data[clazzcourseId][groupId];
        localStorage.setItem('resGroupExpandStatus', JSON.stringify(this.data));
        return this.data[clazzcourseId][groupId];
    },
    set: function (groupId, isExpand) {
        this.data[clazzcourseId][groupId] = isExpand;
        localStorage.setItem('resGroupExpandStatus', JSON.stringify(this.data));
    },
    init: function () {
        var localStorageData = localStorage.getItem('resGroupExpandStatus');
        if (localStorageData) {
            this.data = JSON.parse(localStorageData);
        }
        var resRowBox = $('.res-row-box');
        for (var i = 0; i < resRowBox.length; i++) {
            var groupId = resRowBox.eq(i).attr('data-id');
            var sort = resRowBox.eq(i).find('.hide-div').attr('data-sort');
            if (!this.data[clazzcourseId]) {
                // localStorage 中没有此班课的信息
                this.data[clazzcourseId] = {};
                this.data[clazzcourseId][groupId] = true;
            }
            if (!this.data[clazzcourseId][groupId]) {
                // 包含 false 和 undefined 的
                this.data[clazzcourseId][groupId] = false;
            } else {
                var visiable = switchGroupVisiable(sort);
                switchButtonStyle(visiable, sort);
            }
        }
        localStorage.setItem('resGroupExpandStatus', JSON.stringify(this.data));
    }
};
$(function () {
    resGroupExpandStatus.init();
    // 上传资源时标题字符超出限制并且用户未做修改，系统自动截取并提示用户
    if (uploadFileError === 'file_name_overlength') {
        confirms('提示', '部分资源名称超过 100 字，自动截取前 100 字作为资源名称', '', '', '', 'alert');
        var resIndexUrl = "https://www.mosoteach.cn/web/index.php?c=res&m=index&clazz_course_id=432F3210-2FA6-11EA-BA85-506B4B4A8386";
        history.replaceState('', '', resIndexUrl);
    }
    if (timer) {
        timer.initElement({
            date: $('#release-date'),
            hour: $('#release-hours'),
            minute: $('#release-minutes')
        });
        timer.timeUpdateEvent = function (date, hour, minute) {
            $('#set-date').text(date);
            $('#set-time').text(hour + ':' + minute);
        };
    }
    // 延时加载图片
    // $("img.lazyload").lazyload();

    //　下载云教材弹窗显示的位置
    $('#down-book').css('top', ($(window).height() - 350) / 2);
    // 查看信息弹窗显示的位置
    $('#res-information-box').css('top', ($(window).height() - 600) / 2);
    // 预览图片弹窗的宽高
    $('#preview-img-box').css('height', $(window).height() - 160)
        .css('width', $(window).height() - 160);

    // 预览图片
    var $images = $('#img-view');
    var options = {
        navbar: false,
        scalable: false,
        // inline: true,
        url: 'data-original',
    };
    $images.on({

    }).viewer(options);

    // 搜索
    $('#search-res input').focus(function () {
        $('#search-res').addClass('border-color');
    });
    $('#search-res input').blur(function () {
        $('#search-res').removeClass('border-color');
    });
    $('#search-res .icon-search').click(function () {
        $('#search-res-form').submit();
    });

    // 选择查看资源的方式
    $('#res-view-way i').click(function () {
        var number = $(this).attr('data-number');

        $('#res-view-way i').attr('class', 'icon-circle-blank');
        $('#res-view-way i[data-number=' + number + ']').attr('class', 'icon-ok-circle');

        var thisHref = $(this).attr('data-href');
        window.location.href = thisHref;
    });

    // 点击云教材 显示二维码
    $('.book-info-box').click(function () {
        $('#down-book-box').show();
    });

    // 隐藏（显示）分组下的资源

    $(document).on('click', '.res-row-title .slidedown-button', function () {
        var sort = $(this).attr('data-sort');
        var groupVisiable = switchGroupVisiable(sort);
        switchButtonStyle(groupVisiable, sort);

        var batchOperateStatus = $('#res-view-way button').attr('data-status');
        if (batchOperateStatus != 'N') {
            // 批量操作中
            resGroupExpandStatus.switch($(this).parents('.res-row-box').attr('data-id'));
        }
    });
    function getSelectedDate() {
        var date = new Date();
        var y = date.getFullYear();
        var m = (date.getMonth() + 1 <= 9) ? '0' + (date.getMonth() + 1) : date.getMonth() + 1;
        var d = (date.getDate() <= 9) ? '0' + date.getDate() : date.getDate();

        var dateStr = y + '-' + m + '-' + d;

        var setDate = $('#release-date').datebox('getValue');

        var hours = date.getHours();
        var minutes = date.getMinutes();
        minutes = minutes < 10 ? '0' + minutes : minutes;
        hours = hours < 10 ? '0' + hours : hours;
        var time = hours + "" + minutes;

        var dateBox = $(this).parents('.panel').find('.date-box');
        var h = 0;

        if (dateStr === setDate) {
            if (minutes > 30) {
                if (date.getHours() == 23) {// 如果当前时间等于 23:00 并且大于 分钟大于 30
                    h = 0;
                    $('#release-date').datebox('setValue', y + '-' + m + '-' + (date.getDate() + 1 <= 9 ? '0' + (date.getDate() + 1) : date.getDate() + 1));
                } else {
                    h = date.getHours() * 2 + 2;
                }
            } else {
                h = date.getHours() * 2 + 1;
            }
        }

        var timearr = [];
        for (var i = h; i < 48; i++) {
            timearr.push({
                id: i,
                text: '',
                value: i * 30
            });
        }
        timearr[0]['selected'] = true;
        $('#release-time').combobox('loadData', timearr);

        $('#set-date').text(setDate);
        $('#set-time').text(timearr[0]['text'] + ':00');
    }

    // 设定发布时间
    $(document).on('click', '.set-release-time', function () {
        $('.res-row').attr('data-status', '');
        var targetDate = $(this).parents('.res-row').attr('data-target-date');
        var targetTime = $(this).parents('.res-row').attr('data-target-time');
        setDefaultDateTime(targetDate, targetTime);

        $(this).parents('.res-row').attr('data-status', 'show');
        $('#res-view-way button[data-status=N]').click();

        var dateBox = $(this)[0].getBoundingClientRect();

        $('#release-time-box').css({
            'position': 'absolute',
            'box-shadow': '0 0 5px 0 #CCC',
            'left': dateBox.left - 100,
            'top': dateBox.top + 28 + $(window).scrollTop()
        }).show();
        $('#res_ids').val($(this).parents('.res-row').attr('data-value'));
        timer.run();
        return false;
    });

    easyloader.load(['draggable', 'droppable', 'resizable', 'datebox', 'combobox'], function () {


        // 预设发布时间 禁止选中当前时间之前的时间和日期
        $('#release-date').datebox().datebox('calendar').calendar({
            validator: function (date) {
                return easyuiValidator(date);
            }
        });
        var buttons = $.extend([], $.fn.datebox.defaults.buttons);
        buttons.splice(0, 2);
        $('#release-date').datebox({
            buttons: buttons,
            onSelect: function (date) {
                // 初始化时间
                $('#release-hours').combobox('loadData', easyuiReloadHours($(this))); // 小时范围
                var hour = $('#release-hours').combobox('getValue'); // 获取小时
                $('#release-minutes').combobox('loadData', easyuiReloadMinutes($(this), hour)); // 分钟范围
                var minute = $('#release-minutes').combobox('getValue'); // 获取分钟
                $('#set-date').html($(this).datebox('getValue'));
                $('#set-time').html(hour + ':' + minute);
            }
        });

        $('#release-hours').combobox({
            onSelect: function (record) {
                // var dateBox = $('#release-date').combobox('getValue'); // 获取日期
                $('#release-minutes').combobox('loadData', easyuiReloadMinutes($('#release-date'), record.value)); // 分钟范围
                var minute = $('#release-minutes').combobox('getValue'); // 获取分钟
                $('#set-time').text(record.value + ':' + minute);
            }
        });

        $('#release-minutes').combobox({
            onSelect: function (record) {
                var hour = $('#release-hours').combobox('getValue'); // 获取小时
                $('#set-time').text(hour + ':' + record.value);
            }
        });

        // 立即发布资源
        $(document).on('click', '.immediately-release', function () {
            var resName = $.trim($(this).parents('.res-row').find('.res-name').text());
            var self = $(this);

            confirms('发布资源', '你确定立即发布 ' + resName + ' 吗？', function () {
                var resId = $(self).attr('data-value');
                $('#ids').val(resId);
                $('#release').submit();
            }, '', '');
            return false;
        });

        //按预设的时间发布资源
        $('#release-button').click(function () {
            var setDate = $('#release-date').datebox('getValue');
            var setHours = $('#release-hours').combobox('getValue');
            var setMinutes = $('#release-minutes').combobox('getValue');

            // if (setTime.indexOf(':') < 0)
            //     setTime = MTWeb.formatTimeForCombobox(setTime);

            var releaseTime = setDate + ' ' + setHours + ':' + setMinutes + ':00';
            var ids = $('#res_ids').val();
            var releaseDateObj = turnToDateObj(setDate, setHours, setMinutes);
            var thisTime = new Date();
            if (turnToMinutes(releaseDateObj) - turnToMinutes(thisTime) <= 5) {
                confirms('提示', '你设置的预发布时间距离现在少于5分钟，是否继续', function () {
                    releaseRes(ids, releaseTime);
                }, '', '', '', '', '继续', '');
            } else {
                releaseRes(ids, releaseTime);
            }

            //移除 批量操作 预设发布时间的弹框上定义的类
            $('#img-box').hide();           //隐藏遮罩层
            $('#release-time-box').removeClass('batch-release-time-box');
        });

        // 关闭设置发布时间
        $('#close-button').click(function () {
            $('#release-time-box').hide();
            $('#release-all-bg').hide();

            //移除 批量操作 预设发布时间的弹框上定义的类
            $('#img-box').hide();           //隐藏遮罩层
            $('#release-time-box').removeClass('batch-release-time-box');
            timer.stop();
        });

        // 批量操作
        $('#res-view-way .batch-operation-button').click(function () {
            var buttonStatus = $(this).attr('data-status');
            var webRes = $('.hide-div a');

            if (buttonStatus === 'Y') {
                $('#select-all-res-box').stop().show();
                $('.select-button[data-type=hide]').attr('data-type', 'show');
                $(this).attr('data-status', 'N').text('取消');
                $('.manual-order-button').hide();
                // 展开所有分组
                $('.hide-div').attr('data-status', 'Y').show();
                switchButtonStyle(true);
            } else {
                $('#select-all-res-box').stop().hide();
                $('.select-button[data-type=show]').attr('data-type', 'hide');
                $('.select-button').attr('class', 'icon-check-empty select-button').attr('data-status', 'Y');
                $('.res-row').attr('data-type', 'N');
                $(this).attr('data-status', 'Y').text('批量操作');
                $('#set-time-release-all, #release-all').css({ 'opacity': '1', 'text-decoration': '', 'cursor': 'pointer' });
                $('.manual-order-button').show();
                // 恢复展开收起状态
                var status = ''; // expand or collapse
                var sort = '';
                for (var i in resGroupExpandStatus.data[clazzcourseId]) {
                    if (resGroupExpandStatus.data[clazzcourseId][i]) {
                        // 展开状态
                        status = 'expand';
                    } else {
                        status = 'collapse';
                    }
                    sort = $('.res-row-box[data-id="' + i + '"]').children('.hide-div').attr('data-sort');
                    switchGroupVisiable(sort, status);
                    switchButtonStyle(status === 'expand', sort);
                }
            }

            $('#release-time-box').hide();
            $('#select-all-res-box').removeClass('selected');
            $('.selected-num').text('');
        });
        // 勾选资源/分组
        $(document).on('click', '.select-button', function (e) {
            e.stopPropagation();
            var status = $(this).attr('data-status');
            var buttonType = $(this).attr('data-button-type');

            if (status === 'Y') {
                $(this).attr('class', 'icon-check select-button').attr('data-status', 'N');
                $(this).parents('.res-row').attr('data-type', 'Y');

                if (buttonType === 'group') {
                    $(this).parents('.res-row-box').find('.hide-div .select-button')
                        .attr('class', 'icon-check select-button').attr('data-status', 'N');
                    $(this).parents('.res-row-box').find('.res-row').attr('data-type', 'Y');
                } else if (buttonType === 'all') {
                    $('#res-list-box').find('.select-button').attr('class', 'icon-check select-button').attr('data-status', 'N');
                    $('#res-list-box').find('.res-row').attr('data-type', 'Y');
                }
            } else {
                $(this).attr('class', 'icon-check-empty select-button').attr('data-status', 'Y');
                $(this).parents('.res-row').attr('data-type', 'N');

                if (buttonType === 'group') {
                    $(this).parents('.res-row-box').find('.hide-div .select-button')
                        .attr('class', 'icon-check-empty select-button').attr('data-status', 'Y');
                    $(this).parents('.res-row-box').find('.res-row').attr('data-type', 'N');
                } else if (buttonType === 'all') {
                    $('#res-list-box').find('.select-button').attr('class', 'icon-check-empty select-button').attr('data-status', 'Y');
                    $('#res-list-box').find('.res-row').attr('data-type', 'N');
                }
            }

            if (buttonType === 'row' || buttonType === 'group') {
                if (buttonType === 'row') {
                    var groupRes = $(this).parents('.res-row-box').find('.res-row').size();
                    var groupSelectedResSize = $(this).parents('.res-row-box').find('.res-row[data-type=Y]').size();

                    if (groupRes === groupSelectedResSize) {
                        $(this).parents('.res-row-box').find('.res-row-title .select-button')
                            .attr('class', 'icon-check select-button').attr('data-status', 'N');
                    } else {
                        $(this).parents('.res-row-box').find('.res-row-title .select-button')
                            .attr('class', 'icon-check-empty select-button').attr('data-status', 'Y');
                    }
                }

                if (buttonType === 'row' || buttonType === 'group') {
                    var resSize = $('.res-row').size();
                    var selectedSize = $('.res-row[data-type=Y]').size();
                    if (resSize === selectedSize) {
                        $('.select-all-button i').attr('class', 'icon-check select-button').attr('data-status', 'N');
                    } else {
                        $('.select-all-button i').attr('class', 'icon-check-empty select-button').attr('data-status', 'Y');
                    }
                }
            }

            var size = $('.res-row[data-type=Y]').size();
            var unReleaseSize = $('.res-row[data-type=Y][data-release-status=N]').size();  // 未发布资源数量
            if (size > 0) {
                $('#select-all-res-box').addClass('selected');
                $('.selected-num').text('已选中 ' + size + ' 个资源');

                if (unReleaseSize <= 0) {
                    $('#set-time-release-all, #release-all').css({ 'opacity': '0.7', 'text-decoration': 'none', 'cursor': 'default' });
                } else {
                    $('#set-time-release-all, #release-all').css({ 'opacity': '1', 'text-decoration': '', 'cursor': 'pointer' });
                }
            } else {
                $('#select-all-res-box').removeClass('selected');
                $('.selected-num').text('');
                $('#set-time-release-all, #release-all').css({ 'opacity': '1', 'text-decoration': '', 'cursor': 'pointer' });
            }

            // 已选中的资源 是否有删除的权限
            var selectedRes = $('.res-row[data-type=Y]');
            for (var i = 0; i < selectedRes.length; i++) {
                var deleteResEnable = selectedRes.eq(i).find('.del-res').attr('data-enable') === 'Y';
                if (!deleteResEnable) {
                    break;
                }
            }
            if (i < selectedRes.length) {
                $('#delete-res').attr('data-enable', 'N');
            } else {
                $('#delete-res').attr('data-enable', 'Y');
            }
            return false;
        });

        // 批量发布（立即发布）
        $('#release-all').click(function () {
            var size = $('.res-row[data-type=Y][data-release-status=N]').size();

            if (size <= 0) return;

            confirms('发布资源', '你确定立即发布选中的 ' + size + ' 个资源吗？', function () {

                var ids = [];
                for (var i = 0; i < size; i++) {
                    ids[i] = $('.res-row[data-type=Y][data-release-status=N]').eq(i).attr('data-value');
                }

                $('#ids').val(ids);
                $('#release').submit();
            }, '', '');
        });

        // 批量设置时间发布
        $('#set-time-release-all').click(function () {
            var size = $('.res-row[data-type=Y][data-release-status=N]').size();
            if (size <= 0) return;
            if ($('#select-all-res-box').hasClass('selected')) {
                $('#img-box').show();       //显示遮罩层
            }
            $('#release-time-box').addClass('batch-release-time-box');

            var _left = ($(window).width() - 400) / 2;
            var _top = ($(window).height() - 150) / 2;
            $('#release-all-bg').show();
            $('#release-time-box').css('position', 'fixed')
                //   .css('box-shadow', '#e1e1e1 0px 0px 5px 0px ')
                .css('left', _left)
                .css('top', _top)
                .show();

            var ids = [];
            for (var i = 0; i < size; i++) {
                ids[i] = $('.res-row[data-type=Y][data-release-status=N]').eq(i).attr('data-value');
            }
            $('#res_ids').val(ids);

            var t = new Date();
            var tomorrow = new Date(t.getTime() + 85400000);
            var r_year = tomorrow.getFullYear();
            var r_month = tomorrow.getMonth() + 1;
            var r_date = tomorrow.getDate();
            $('#release-date').datebox('setValue', r_year + '-' + r_month + '-' + r_date);

            $('#release-hours').combobox('loadData', easyuiReloadHours($('#release-date')));
            $('#release-minutes').combobox('loadData', easyuiReloadMinutes($('#release-hours'), '08'));

            $('#release-hours').combobox('setValue', '08');
            $('#release-minutes').combobox('setValue', '00');

            $('#set-date').text(r_year + '-' + r_month + '-' + r_date);
            $('#set-time').text('08:00');
            timer.run();
        });

        $('.close-tips-box').click(function () {
            $('#img-box').hide();       //隐藏遮罩层
            initReleaseTimeBox();
            $('#release-time-box').removeClass('batch-release-time-box').hide();
        });

    });


    /*初始化预设发布时间*/
    function initReleaseTimeBox() {
        var t = new Date();
        var tomorrow = new Date(t.getTime() + 85400000);
        var r_year = tomorrow.getFullYear();
        var r_month = tomorrow.getMonth() + 1;
        var r_date = tomorrow.getDate();
        $('#release-date').datebox('setValue', r_year + '-' + r_month + '-' + r_date);

        $('#release-hours').combobox('loadData', easyuiReloadHours($('#release-date')));
        $('#release-minutes').combobox('loadData', easyuiReloadMinutes($('#release-hours'), '08'));

        $('#release-hours').combobox('setValue', '08');
        $('#release-minutes').combobox('setValue', '00');

        $('#set-date').text(r_year + '-' + r_month + '-' + r_date);
        $('#set-time').text('08:00');
    }
    // 查看信息
    $(document).on('click', '.button-box div', function () {
        var type = $(this).attr('data-type');
        if (type === 'show') return;

        $('.button-box div').attr('data-type', 'hide');
        if (type === 'hide') {
            $(this).attr('data-type', 'show');
        }

        var value = $(this).attr('data-value');
        if (value === '1') {
            $('#not-involved').show();
            $('#already-participate').hide();
            $('#member-list').css('height', '285px')
        } else {
            $('#already-participate').show();
            $('#not-involved').hide();
            $('#member-list').css('height', '300px')
        }
        return false;
    });

    // 提醒查看资源
    $('.remind-member button').click(function () {
        var value = $(this).attr('data-value');
        var self = $(this);
        if (value === '1') {
            var s = 11;
            re = setInterval(function () {
                if (s <= 0) {
                    $(self).attr('data-value', '1').text('提醒未查看');
                    clearInterval(re);
                } else {
                    s--;
                    $(self).text('再次点击确定提醒(' + s + ')');
                }
            }, 1000);
            $(self).attr('data-value', '2');
        }

        if (value === '2') {
            var id = $('#res-id').val();

            if (id.length <= 0) return;

            $.ajax({
                type: "POST",
                url: "https://www.mosoteach.cn/web/index.php?c=msg&m=push_remind",
                data: {
                    'entity_id': id,
                    'cc_id': '432F3210-2FA6-11EA-BA85-506B4B4A8386',
                    'type': 'N_V_R'
                },
                dataType: "json",
                success: function (msg) {
                    switch (msg.result_code) {
                        case 0:
                            $('.remind-member span').css('color', '#999').text(msg.push_time.slice(0, 10));
                            $('.remind-member button').hide()
                            $('.remind-member div').css('color', '#999')
                                .css('float', 'right')
                                .text('已提醒未查看的同学');
                            break;
                        case 2013:
                            confirms('提示', msg.result_msg, function () {
                                window.location.reload();
                            }, '', '', 'alert');
                            break;
                        default:
                            commonError.handleFunc(msg.result_code);
                            break;
                    }
                }
            });

            $(self).attr('data-value', '1').text('提醒未查看');
        }
    });

    // 删除资源
    $(document).on('click', '.del-res', function () {
        if ($(this).attr('data-enable') !== 'Y') return;
        var ids = [];
        ids[0] = $(this).attr('data-value');

        if (ids.length <= 0) return;
        var resName = $(this).parents('.res-row').find('.res-name').text();
        var resReleased = $(this).parents('.res-row').attr('data-release-status') === 'Y'; // 资源已发布
        var revokeScoreCheckBox = onlyDeleteResouce && resReleased ? 'Y' : 'N'; // 选择是否回收经验值的 checkbox
        // 删除确认弹窗的文案
        var deleteConfirmsContent = {
            hint: '',
            sureTitle: '',
            cancelTitle: ''
        };
        if (userPermissionDeleteEveryRes) {
            deleteConfirmsContent.hint = '你确定删除 ' + resName + ' 吗？';
        } else {
            deleteConfirmsContent.hint = '资源删除后不可恢复，删除资源时产生的经验值将被收回';
            deleteConfirmsContent.sureTitle = '删除';
        }
        confirms('删除资源', deleteConfirmsContent.hint, function () {
            // 是否同时回收学生参加查看资源的经验值
            var isDelExp = $('#del-experience-input').val();
            if (!onlyDeleteResouce) {
                isDelExp = 'Y';
            }
            showLoading();
            $.ajax({
                type: "POST",
                url: "https://www.mosoteach.cn/web/index.php?c=res&m=delete",
                data: {
                    'ids': ids,
                    'revoke_student_score': isDelExp,
                    'clazz_course_id': clazzcourseId
                },
                dataType: "json",
                success: function (msg) {
                    if (msg.result_code === 0) {
                        window.location.reload();
                    } else {
                        commonError.handleFunc(msg.result_code);
                    }
                    hideLoading();
                }
            });
        }, '', revokeScoreCheckBox, '', '', deleteConfirmsContent.sureTitle, deleteConfirmsContent.cancenTitle);
        return false;
    });

    // 批量删除资源
    $('#delete-res').click(function () {
        if ($(this).attr('data-enable') !== 'Y') return;
        var size = $('.res-row[data-type=Y]').size();
        if (size <= 0) return;
        var resReleased = false; // 批量操作的资源是否包含已发布的

        var ids = [];
        for (var i = 0; i < size; i++) {
            var resRow = $('.res-row[data-type=Y]').eq(i);
            ids[i] = resRow.attr('data-value');
            if (!resReleased && resRow.attr('data-release-status') === 'Y') {
                resReleased = true;
            }
        }
        var revokeScoreCheckBox = onlyDeleteResouce && resReleased ? 'Y' : 'N'; // 选择是否回收经验值的 checkbox

        // 删除确认弹窗的文案
        var deleteConfirmsContent = {
            hint: '',
            sureTitle: '',
            cancelTitle: ''
        };
        if (userPermissionDeleteEveryRes) {
            deleteConfirmsContent.hint = '你确定删除选中的 ' + size + ' 个资源吗？';
        } else {
            deleteConfirmsContent.hint = '资源删除后不可恢复。';
            deleteConfirmsContent.sureTitle = '删除';
        }

        confirms('删除资源', deleteConfirmsContent.hint, function () {
            // 是否同时回收学生参加查看资源的经验值
            var isDelExp = $('#del-experience-input').val();

            showLoading();
            $.ajax({
                type: "POST",
                url: "https://www.mosoteach.cn/web/index.php?c=res&m=delete",
                data: {
                    'ids': ids,
                    'revoke_student_score': isDelExp,
                    'clazz_course_id': clazzcourseId
                },
                dataType: "json",
                success: function (msg) {
                    if (msg.result_code === 0) {
                        window.location.reload();
                    } else {
                        commonError.handleFunc(msg.result_code);
                    }
                    hideLoading();
                }
            });
        }, '', revokeScoreCheckBox, '', '', deleteConfirmsContent.sureTitle, deleteConfirmsContent.cancelTitle);
    });

    // 下载
    $(document).on('click', '.download-res', function () {
        if (resManualOrder) return;
        var batchOperateStatus = $('#res-view-way button').attr('data-status');
        if (batchOperateStatus === 'N') { // 批量操作中
            $(this).find('.select-button').click();
            return;
        }
        var resId = $(this).attr('data-value');
        cannotPreview(resId);
    });

    //转发资源
    $(document).on('click', '.forward_res', function () {
        var id = $(this).attr('data-value');
        var resName = $.trim($(this).parents('.res-row').find('.res-name').text());
        var imgSrc = $(this).parents('.res-row').find('.res-icon').attr('src');

        var data = [{
            'ids': id,
            'res_name': resName,
            'img_src': imgSrc
        }]

        var json_data = JSON.stringify(data);

        $('#forward-res .res_data').val(json_data);
        $('#forward-res').submit();
        return false;
    });

    // 批量转发资源
    $('#forward-res-rows').click(function () {
        var size = $('.res-row[data-type=Y]').size();
        if (size <= 0) return;

        var data = [];
        for (var i = 0; i < size; i++) {
            var tmp_arr = {
                'ids': $('.res-row[data-type=Y]').eq(i).attr('data-value'),
                'res_name': $.trim($('.res-row[data-type=Y]').eq(i).find('.res-name').text()),
                'img_src': $('.res-row[data-type=Y]').eq(i).find('.res-icon').attr('src')
            }
            data.push(tmp_arr);
        }

        var json_data = JSON.stringify(data);
        $('#forward-res .res_data').val(json_data);
        $('#forward-res').submit();
    });

    // 关闭显示信息
    $('#close-res-info').click(function () {
        $('#res-information-bg').hide();
        $('.descriptive-text').addClass('show-text-all').attr('data-type', 'N');
        $('#res-id').val('');
        clearInterval(re);
        // 回复dialog的初始样式
        $('.remind-member button').attr('data-value', '1').text('提醒未查看');
        $('.partake-menber-box').show();
        $('#res-information-box').find('.clear30').show();
        $('#res-information-box').find('.clear30').show();
        $('.remind-member').show();
        $('.remind-member').next('.clear15').show();
    });
    // 预览资源
    $(document).on('click', '.preview', function () {
        var id = $(this).attr('data-value');
        var resName = $(this).find('.res-name').text();

        var batchOperateStatus = $('#res-view-way button').attr('data-status');
        if (batchOperateStatus === 'N') { // 批量操作中
            $(this).find('.select-button').click();
            return;
        }
        if (resManualOrder) return;
        if (id.length <= 0)
            return;
        if ($(this).find('span[data-is-drag="Y"]').length > 0)
            dataIsDrag = true;

        preview(id, resName);
    });

    $(document).on('click', '.nopreview', function () {
        if (resManualOrder) return;
        confirms('预览失败', '该资源暂不能预览，请下载后查看', '', '', 'N', 'alert');
    });
    $(document).on('click', '.res-icon', function (e) {
        e.stopPropagation();
        if (resManualOrder) {
            e.preventDefault();
        }
    });
    $(document).on('click', '.res-row.web', function () {
        if (resManualOrder) return;
        var batchOperateStatus = $('#res-view-way button').attr('data-status');
        if (batchOperateStatus === 'N') { // 批量操作中
            $(this).find('.select-button').click();
            return false;
        }
        $(this).find('.res-icon').click();
    });
    $(document).on('click', '.preview-file', function () {
        if (resManualOrder) return;
        var batchOperateStatus = $('#res-view-way button').attr('data-status');
        if (batchOperateStatus === 'N') { // 批量操作中
            $(this).find('.select-button').click();
            return;
        }

        var length = parseInt($(this).attr('data-length'));
        if (length > 50 * 1024 * 102) {
            confirms('预览失败', '超过 50MB 的文档，不支持在线预览，请在手机版云班课下载和查阅', '', '', 'N', 'alert');
            return;
        }

        var id = $(this).attr('data-value');

        window.open("https://www.mosoteach.cn/web/index.php?c=res&m=online_preview&clazz_course_id=432F3210-2FA6-11EA-BA85-506B4B4A8386" + '&file_id=' + id);
    });

    // 编辑资源
    $(document).on('click', '.edit-res', function () {
        var href = $(this).attr('data-href');
        if (href.length <= 0) return;

        window.location.href = href;
        return false;
    });

    // 查看信息
    $(document).on('click', '.show-info', function () {
        var targetRes = $(this).parents('.res-row');
        var id = targetRes.attr('data-value');
        var name = targetRes.find('.res-name').text();
        var operaterId = targetRes.attr('data-operater-id');

        if (userPermissionOther && (operaterId != createrId)) {
            var operaterRole = targetRes.attr('data-operater-role');
            var operaterName = targetRes.attr('data-operater-name');
            $('#operater-title').text(operaterRole += operaterName);
            $('.res-operater').show();
        } else {
            $('.res-operater').hide();
        }

        if (id.length <= 0 || name.length <= 0) return;

        var roleType = $(this).attr('data-role-type');
        if (roleType != 'TEACHER' || $(this).parents('.res-row').attr('data-release-status') === 'N') {
            $('.partake-menber-box').hide();
            $('#res-information-box').find('.clear30').hide();
            $('.remind-member').hide();

            var resName = $('.res-row[data-value=' + id + ']').find('.res-name').text();
            $('#title-text').text(resName).attr('title', resName);
            $('#kp').text($('#kps-' + id).text());
            $('#learn_req').text($('#learn_req-' + id).text());
            $('#purpose-type').text(_moso.getUseType($('#purpose-' + id).text()));

            $('#res-information-bg').show();

            // 重新计算dialog的垂直位置
            var infoAlertTop = $('#res-information-box').innerHeight() / 2;
            $('#res-information-box').css({ 'top': '50%', 'margin-top': -infoAlertTop });
        } else {
            var mime = $(this).parents('.res-row').attr('data-mime');
            showInfo(id, name, mime);
        }
        $('.button-box div[data-value=1]').click();
    });

    // 展开收起分组
    $(document).on('click', '.manual-order.switch-group-visiable', function () {
        var sort = $(this).attr('data-sort');
        var groupVisiable = switchGroupVisiable(sort);
        switchButtonStyle(groupVisiable, sort);
        var groupId = $(this).parents('.res-row-box').attr('data-id');
        manualOrderGroupExpandStatusCache[groupId] = groupVisiable;
    });
    // 进入调序
    $('.manual-order-button').click(function () {
        showLoading();
        setTimeout(function () {
            switchManualOrderView('enter');
            hideLoading();
        }, 200);
    });
    // 退出调序
    $('.cancel-manual-order').click(function () {
        location.reload();
    });
    // 保存到服务器
    $('.save-manual-order').click(function () {
        saveOrder();
    });
    // 发送调序请求
    function saveOrder() {
        if (!manualOrderGroup && manualOrderResGroup.length == 0) {
            switchManualOrderView('exit');
        }
        // 保存分组展开状态
        for (var i in manualOrderGroupExpandStatusCache) {
            resGroupExpandStatus.set(i, manualOrderGroupExpandStatusCache[i]);
        }
        manualOrderGroupExpandStatusCache = {};
        if (manualOrderGroup) {
            showLoading();
            var groupOrder = {
                clazz_course_id: clazzcourseId,
                item_order: []
            };
            var groupList = $('.res-row-box');
            for (var i = 0; i < groups.length; i++) {
                var group = groupList.eq(i);
                groupOrder.item_order.push({
                    key: group.attr('data-id'),
                    order: i + 1
                });
            }
            requestSaveGroupOrder(groupOrder);
        }
        if (manualOrderResGroup.length != 0) {
            showLoading();
            var resOrder = {};
            for (var i = 0; i < manualOrderResGroup.length; i++) {
                var groupId = manualOrderResGroup[i];
                resOrder = {
                    cc_id: clazzcourseId,
                    group_id: groupId,
                    item_order: []
                };
                var group = $('.res-row-box[data-id="' + groupId + '"]');
                var resRowList = group.find('.res-row[data-release-status="Y"]');
                for (var j = 0; j < resRowList.length; j++) {
                    resOrder.item_order.push({
                        key: resRowList.eq(j).attr('data-value'),
                        order: j + 1
                    });
                }
                requestSaveResOrder(resOrder, groupId);
            }
        }
    }
});
function switchButtonStyle(groupVisiable, sort) {
    var btn1, btn2;
    if (sort != undefined) {
        btn1 = $('.slidedown-button[data-sort="' + sort + '"]');
        btn2 = $('.switch-group-visiable[data-sort="' + sort + '"]');
    } else {
        btn1 = $('.slidedown-button');
        btn2 = $('.switch-group-visiable');
    }

    if (groupVisiable) {
        btn1.addClass('icon-angle-up').removeClass('icon-angle-down');
        btn2.removeClass('expand').addClass('collapse');
    } else {
        btn1.removeClass('icon-angle-up').addClass('icon-angle-down');
        btn2.addClass('expand').removeClass('collapse');
    }
}
/**
    * 收起/展开 分组
    * @param sort [String]  hide-div 的索引
    * @param isExpand [String]  手动设置展开(expand)/收起(collapse)。如果不设置此参数，默认为切换到另一状态
    * @return [Boolean] 该元素是否显示
    */
function switchGroupVisiable(sort, isExpand) {
    var hideDiv = $('.hide-div[data-sort=' + sort + ']');
    if (hideDiv.length === 0) return;
    var status = '';
    if (isExpand) {
        status = (isExpand === 'expand' ? 'N' : 'Y');
    } else {
        status = hideDiv.attr('data-status');
    }
    if (status === 'Y') {
        hideDiv.attr('data-status', 'N').stop().hide();
    } else {
        hideDiv.attr('data-status', 'Y').stop().show();
    }
    return status === 'N';
}
// 保存分组顺序到服务器
function requestSaveGroupOrder(groupOrderList) {
    requestCount++;
    $.ajax({
        type: "post",
        dataType: "json",
        url: "https://www.mosoteach.cn/web/index.php?c=group&m=change_order",
        data: {
            content: JSON.stringify(groupOrderList),
            clazz_course_id: clazzcourseId
        },
        success: function (msg) {
            requestCount--;
            if (msg.result_code === 0) {
                manualOrderGroup = false;
            }
            requestComplete(msg.result_code);
        },
        error: function (msg) {

        }
    });
}
// 保存组内资源顺序到服务器
function requestSaveResOrder(resOrderList, groupId) {
    requestCount++;
    $.ajax({
        type: "post",
        dataType: "json",
        url: "https://www.mosoteach.cn/web/index.php?c=res&m=save_res_order",
        data: {
            clazz_course_id: clazzcourseId,
            res_order_list: JSON.stringify(resOrderList)
        },
        success: function (msg) {
            requestCount--;
            if (msg.result_code === 0) {
                var index = $.inArray(groupId, manualOrderResGroup);
                if (index >= 0) {
                    manualOrderResGroup.splice(index, 1);
                }
            }
            requestComplete(msg.result_code);
        },
        error: function (msg) {

        }
    });
}
// 请求全部完成退出调序模式
function requestComplete(resultCode) {
    if (requestCount === 0) {
        hideLoading();
        if (!manualOrderGroup && (manualOrderResGroup.length === 0) && (resultCode === 0)) {
            // 全部成功
            switchManualOrderView('exit');
            successTips('保存成功', 500, 2500, 500);
        } else {
            if (resultCode != 0) {
                switch (resultCode) {
                    case 2006:
                        confirms('提示', '班课已关闭，不可再对资源进行调序', function () {
                            showLoading();
                            location.reload();
                        }, '', '', 'alert', function () {
                            showLoading();
                            location.reload();
                        });
                        break;
                    default:
                        commonError.handleFunc(resultCode);
                        break;
                }
            }
        }
    }
}
/**
 * 按设定的时间发布资源
 * @param [type] string 资源的id
 * @param [type] string 发布的时间
 */
function releaseRes(ids, releaseTime) {
    if (ids.length <= 0 || releaseTime.length <= 0) {
        return;
    }
    showLoading();
    $.ajax({
        type: "post",
        url: "https://www.mosoteach.cn/web/index.php?c=res&m=set_release_time",
        data: {
            'clazz_course_id': clazzcourseId,
            'order_item': "group",
            'ids': ids,
            'release_time': releaseTime
        },
        dataType: "json",
        success: function (msg) {
            if (msg.result_code === 0) {
                location.reload();
            } else {
                hideLoading();
                switch (msg.result_code) {
                    case 1101:
                        confirms('提示', '你预设的发布时间早于当前时间，你可以直接选择发布资源，也可以重新设置发布时间', '', '', 'alert');
                        break;
                    default:
                        commonError.handleFunc(msg.result_code);
                }
            }
        }
    });
}

/**
 * 设置发布时间时 选中当前日期时 将选择时间的下拉框的数据重新载入
 */
function reloadTime() {
    var timearr = [];
    for (var i = 0; i < 48; i++) {
        timearr.push({
            id: i,
            text: '',
            value: i * 30
        });
    }
    timearr[0]['selected'] = true;
    $('#release-time').combobox('loadData', timearr);
}
/**
 * 查看资源信息
 * @param [type] string 资源id
 * @param [type] string 资源名称
 * @param [type] string N 学生身份
 */
function showInfo(id, resName, type) {
    if (id.length <= 0) return;
    showLoading();
    $.ajax({
        type: "POST",
        url: "https://www.mosoteach.cn/web/index.php?c=res&m=detial",
        data: {
            'file_id': id
        },
        dataType: "json",
        success: function (msg) {
            if (msg.result_code === 0) {
                $('#not-involved').empty();
                $('#already-participate').empty();

                $('#res-id').val(id);
                $('#title-text').text(resName).attr('title', resName);
                $('#kp').text($('#kps-' + id).text());
                $('#learn_req').text($('#learn_req-' + id).text());
                $('#purpose-type').text(_moso.getUseType($('#purpose-' + id).text()));
                $('#viewed').text('已查看 ' + msg.viewed.length + ' 人');
                $('#unview').text('未查看 ' + msg.unview.length + ' 人');

                var ul1 = $('<ul>');
                for (var i = 0; i < msg.unview.length; i++) {
                    var li1 = $('<li>');
                    var span1 = $('<span>').attr('class', 'member-name').text(msg.unview[i]['full_name']);
                    var span2 = $('<span>').attr('class', 'student-no').text(msg.unview[i]['student_no']);

                    span1.appendTo(li1);
                    span2.appendTo(li1);
                    li1.attr('class', 'no-check');
                    li1.appendTo(ul1);
                }

                var ul2 = $('<ul>');
                var not_in_clazz = [];
                for (var k = 0; k < msg.viewed.length; k++) {
                    var first = '首次查看';
                    if (msg.viewed[k]['create_time']) {
                        var create_time = msg.viewed[k]['create_time'].replace(/-/g, '/');
                        var t = new Date(create_time);
                        t = t.Format("yyyy.MM.dd hh:mm");
                    } else {
                        t = '';

                    }

                    var li2 = $('<li>');
                    var div1 = $('<div>');
                    var div2 = $('<div>');
                    var span3 = $('<span>').attr('class', 'member-name').text(msg.viewed[k]['full_name']);
                    var span4 = $('<span>').attr('class', 'student-no').text(msg.viewed[k]['student_no']);
                    var span_datetime = $('<span>').attr('class', 'datetime').text(t);
                    var span_first_time = $('<span>').attr('class', 'first-time').text(first);

                    span3.appendTo(div1);
                    span_first_time.appendTo(div1);
                    span_datetime.appendTo(div1);

                    span4.appendTo(div2);
                    if (msg.viewed[k]['in_cc_flag'] == 'N') {
                        var span_in_clazz = $('<span>').attr('class', 'in-clazz').text('已退出班课');
                        span_in_clazz.appendTo(div2);
                        li2.attr('style', 'color:#999');
                    } else {
                        if (type == 'video' || type == 'VIDEO') {
                            var span5 = $('<span>').attr('class', 'img-video').html('<img src="https://static.cdn.oss.mosoteach.cn/mosoteach2/common/images/resource-icon-video.png" style="height:8px" alt="">');
                            var span6 = $('<span>').attr('class', 'first-time').text(msg.viewed[k]['progress'] + '%');
                            span6.appendTo(div2);
                            span5.appendTo(div2);
                        }
                    }

                    div1.appendTo(li2);
                    div2.appendTo(li2);
                    li2.attr('class', 'already-check');
                    if (msg.viewed[k]['in_cc_flag'] == 'N') {
                        not_in_clazz.push(li2)
                    } else {
                        li2.appendTo(ul2);
                    }
                }
                // 不再班课的加到列表的最后面
                var not_in_clazz_len = not_in_clazz.length;
                for (var i = 0; i < not_in_clazz_len; i++) {
                    $(not_in_clazz[i]).appendTo(ul2);
                }
                ul1.appendTo($('#not-involved'));
                ul2.appendTo($('#already-participate'));
                if (msg.unview.length == 0) {
                    $('.remind-member').hide();
                    $('.remind-member').next('.clear15').hide();
                    $('#res-information-box').css('height', 'auto');
                } else {
                    if (msg.allow_push_remind === 'N') {
                        $('.remind-member span').css('color', '#999').text(msg.last_push_remind_time);
                        $('.remind-member button').hide()
                        $('.remind-member div').css('color', '#999')
                            .css('float', 'right')
                            .text('已提醒未查看的同学');
                    } else {
                        $('.remind-member span').css('color', '#FF3300').text('每个已发布的资源只能提醒一次');
                        $('.remind-member button').show()
                        $('.remind-member div').text('');
                    }
                }
                $('#res-information-bg').show();
                var infoAlertTop = $('#res-information-box').innerHeight() / 2;
                $('#res-information-box').css({ 'top': '50%', 'margin-top': -infoAlertTop });
                hideLoading();
            } else {
                commonError.handleFunc(msg.result_code);
            }
        }
    });
    return false;
}
/**
 * 预览资源 点击资源缩略图或者资源名称进行预览
 * @param [type] string 资源的 id
 * @param [type] string 资源的名称
 */
var continueLoading = 'Y';
function preview(id, resName) {
    if (id.length <= 0) return;
    continueLoading = 'Y';
    showLoading();
    $.ajax({
        type: "POST",
        url: "https://www.mosoteach.cn/web/index.php?c=res&m=request_url_for_json",
        data: {
            'file_id': id,
            'type': 'VIEW',
            'clazz_course_id': clazzcourseId
        },
        dataType: "json",
        success: function (msg) {
            if (msg.result_code != 0) {
                commonError.handleFunc(msg.result_code);
                return;
            }

            switch (msg.mime) {
                case 'video':
                    mediaType = 'video';
                    //  获取视频的观看历史
                    $.ajax({
                        type: 'POST',
                        dataType: 'json',
                        url: 'https://www.mosoteach.cn/web/index.php?c=res&m=get_video_record',
                        data: {
                            res_id: id,
                        },
                        success: function (videoRecord) {
                            hideLoading();
                            switch (videoRecord.result_code) {
                                case 1101:
                                    confirms('提示', '视频资源被删除或不存在', function () {
                                        window.reload();
                                    }, '', '', 'alert');
                                    break;
                                case 0:

                                    //TODO
                                    if (videoRecord.data.watch_to <= 0 || !videoRecord.data.watch_to) {
                                        videoRecord.data.watch_to = 0;
                                    }
                                    if (videoRecord.data.last_watch_to <= 0 || !videoRecord.data.last_watch_to) {
                                        videoRecord.data.last_watch_to = 0;
                                    }
                                    // 初始化观看进度
                                    videoWatchTo = videoRecord.data.watch_to;
                                    videoLastWatchTo = videoRecord.data.last_watch_to;
                                    watchingResId = id;
                                    start = videoLastWatchTo;
                                    $('.video-watch-to, .video-current-time').css('width', '0px');
                                    // $('.res-row[data-value=' + id + ']').attr('data-watch-to', videoRecord.data.watch_to); //  历史最大进度
                                    // $('.res-row[data-value=' + id + ']').attr('data-last-watch-to', videoRecord.data.last_watch_to);    // 最后一次的进度
                                    $('.shadow-box').css('top', '0px').show();
                                    $('.preview-video').css('top', '10%');
                                    $('.preview-audio').hide();
                                    myPlayer.setSrc(msg.src);

                                    /* 如果视频地址是m3u8,setSrc()函数执行时间很长，
                                     * 在 myPlayer.setSrc(msg.src) 后直接执行 myPlayer.play() 会因为 myPlay.src 没有值而报错，
                                     * 测试中，需要 20~30毫秒 myPlay.src 才会有值，所以这里用 setInterval 等待了一下，如果等待时间
                                     * 超过 1s ，则不会自动播放
                                    */
                                    var count = 0;
                                    var int = setInterval(function () {
                                        count++;
                                        if (myPlayer.src) {
                                            clearInterval(int);
                                            myPlayer.play();
                                        }
                                        if (count > 100) {
                                            clearInterval(int);
                                        }
                                    }, 10);

                                    if ($('.res-row[data-value=' + watchingResId + ']').attr('data-drag') === 'N' && (!userPermissionOther)) {
                                        $('#cant-drag').stop().fadeIn(300).delay(2500).fadeOut(300);
                                        isNotDrag = true;
                                    }
                                    break;
                                default:
                                    commonError.handleFunc(videoRecord.result_code);
                                    break;
                            }


                        },
                    });
                    break;




                case 'audio':
                    hideLoading();
                    mediaType = 'audio';
                    $('.shadow-box').css('top', '0px').show();
                    $('.preview-video').css('top', '-20000px');
                    $('.preview-audio').show();
                    var windowWidth = $(window).width();
                    var windowHeight = $(window).height();
                    var audioWidth = $('.preview-audio').width();
                    var audioHeight = $('.preview-audio').height();
                    var marginTop = (windowHeight - audioHeight) / 2;
                    var marginLeft = (windowWidth - 400) / 2;
                    myPlayerAudio.setSrc(msg.src);
                    // myPlayerAudio.load();
                    myPlayerAudio.play();
                    break;
                case 'image':
                    $('#img-view').attr('src', msg.src)
                        .attr('data-original', msg.src)
                        .attr('alt', html_encode(html_encode(resName)));
                    $('#img-view').load(function () {
                        if (continueLoading === 'Y') {
                            hideLoading();
                            $(this).click();
                        } else {
                            $(this).attr({ 'src': '', 'data-original': '' });
                        }
                    });
                    break;
                case 'application':

                    hideLoading();
                    break;
                case 'mosoink':
                    window.open(msg.src);
                    hideLoading();
                    break;
            }
        }
    });
}

/**
 * 查看信息时　显示标题，知识点，学习要求被影藏的文字
 */
function showText(number) {
    var self = $('.descriptive-text[data-value=' + number + ']');
    var status = $(self).attr('data-type');
    if (status === 'N') {
        $(self).removeClass('show-text-all').attr('data-type', 'Y');
    } else {
        $(self).addClass('show-text-all').attr('data-type', 'N');
    }
}
var curUserId = '8D305132-C2FA-11E8-AA22-7CD30AD36C02';

var videoWatchTo = 0; // 最大位置
var videoLastWatchTo = 0; // 上次观看到的位置
var isPlaying = false; // 判断是否正在播放视频
var watchingResId;  //  存储当前观看资源的id
var mediaType; // 存储媒体类型
var start = videoLastWatchTo;  //设置不可拖动进度条
var isNotDrag = false;  //老师设置不可拖动进度条
var isUpdateWatchTo = true;
// 判断是web 浏览器还是手机浏览器打开
var system = { win: false, mac: false, xll: false, ipad: false };
var p = navigator.platform;
var issMobile = "Y";
system.win = p.indexOf("Win") == 0;
system.mac = p.indexOf("Mac") == 0;
system.x11 = (p == "X11") || (p.indexOf("Linux") == 0);
system.ipad = (navigator.userAgent.match(/iPad/i) != null) ? true : false;
if (system.win || system.mac || system.xll || system.ipad) {
    issMobile = "N";
}
$('video').mediaelementplayer({
    plugins: ['flash'],
    features: ['playpause', 'current', 'duration', 'tracks', 'volume', 'fullscreen'],
    clickToPlayPause: true,
    error: function (errorMsg) {
        $('.shadow-box').hide();
        cannotPreview(watchingResId);
    },
    success: function (element) {
        myPlayer = element;
        element.addEventListener('playing', function () {
            if (isPlaying) return;
            // 以下程序仅执行一次
            isPlaying = true;
            myPlayer.setCurrentTime(videoLastWatchTo);
            var dragAllowed = $('.res-row[data-value=' + watchingResId + ']').attr('data-drag');
            if (userPermissionOther || dragAllowed === 'Y') {
                videoWatchTo = myPlayer.duration;
            }
        });
        element.addEventListener('pause', function () {
            if (!isPlaying) return;
            isPlaying = false;
            saveWatchTo();
        });
        element.addEventListener('timeupdate', function () {
            if (isNaN(myPlayer.duration) || isNaN(myPlayer.currentTime)) return;
            if (isPlaying) {
                videoLastWatchTo = myPlayer.currentTime;
            }
            // 需要判断是否是移动端
            if (issMobile === "Y") {
                // dataIsDrag = true 是能拖动，说明已经播放完一遍了。
                if (isNotDrag && !dataIsDrag) {
                    // 记录的最大值小于当前播放的位置时无法拖动
                    if (videoWatchTo < myPlayer.currentTime) {
                        var last = myPlayer.currentTime;
                        if (last - start > 1.0) {
                            isUpdateWatchTo = false;
                            myPlayer.setCurrentTime(start);

                        } else {
                            start = last;
                        }

                    }
                    dataIsDrag = false;
                }
                // 更新最大值
                if (videoLastWatchTo >= videoWatchTo && isUpdateWatchTo) {
                    videoWatchTo = videoLastWatchTo;
                }
                isUpdateWatchTo = true;
            } else {
                if (videoLastWatchTo >= videoWatchTo) {
                    videoWatchTo = videoLastWatchTo;
                }
            }
            // 播放到结尾时归零
            if (videoLastWatchTo == myPlayer.duration) {
                videoLastWatchTo = 0;
                myPlayer.setCurrentTime(videoLastWatchTo);
            }

            // 实时进度条
            var played_percent = Math.ceil(myPlayer.currentTime) / Math.ceil(myPlayer.duration) * 100 + '%';
            $('.video-current-time').css({ 'width': played_percent });
            // 最大进度条
            var videoWatchToPercent = Math.ceil(videoWatchTo) / Math.ceil(myPlayer.duration) * 100 + '%';
            $('.video-watch-to').css({ 'width': videoWatchToPercent });
        });
    }
});
$('audio').mediaelementplayer({
    enablePluginDebug: false,
    plugins: ['flash'],
    AudioWidth: 400,
    AudioHeight: 30,
    success: function (media, node, player) {
        myPlayerAudio = media;
        myPlayerAudio.addEventListener('playing', function () {
            isPlaying = true;
        });
        myPlayerAudio.addEventListener('pause', function () {
            if (!isPlaying) return;
            isPlaying = false;
        });
    }
});
/**
 * 保存视频进度
 * @param  string res_id      [description]
 * @param  number currentTime [description]
 * @param  number duration    [description]
 * @return void
 */
function saveWatchTo() {
    $.ajax({
        type: 'post',
        dataType: 'json',
        url: 'https://www.mosoteach.cn/web/index.php?c=res&m=save_watch_to',
        data: {
            clazz_course_id: clazzcourseId,
            res_id: watchingResId,
            watch_to: Math.ceil(videoWatchTo),
            duration: Math.ceil(myPlayer.duration),
            current_watch_to: Math.ceil(myPlayer.currentTime)
        },
        success: function () {

        }
    });
}
// 点选视频时间点
$('.video-watch-to, .video-current-time').click(function (e) {
    var durationWidth = $('.video-duration').innerWidth();
    var currentWidth = e.pageX - $('.video-duration').offset().left;  //  目标进度
    var percentCurrentTime = currentWidth / durationWidth;  //  当前宽度与总的百分比
    if (!myPlayer.duration) {
        return;
    }
    var currentTime = myPlayer.duration * percentCurrentTime;
    myPlayer.setCurrentTime(currentTime);
    videoLastWatchTo = currentTime;
});
//  关闭预览
$('.close-window').click(function () {
    if (mediaType === 'video') {
        if (isPlaying) {
            myPlayer.pause();
        } else {
            saveWatchTo();
        }
    } else {
        if (isPlaying) {
            myPlayerAudio.pause();
        }
    }
    $('#cant-drag').stop();
    $('.shadow-box').delay(200).fadeOut('fast');
});
//  关闭按钮的移入移出
$('.close-window').hover(function () {
    $(this).css('background-image', 'url(https://static.cdn.oss.mosoteach.cn/mosoteach2/common/images/close-preview-hover.png)')
}, function () {
    $(this).css('background-image', 'url(https://static.cdn.oss.mosoteach.cn/mosoteach2/common/images/close-preview-normal.png)')
});
function previewWebRes(_this) {
    $(_this).find('.select-button').click();
}

function cannotPreview(errorResId) {
    if (!errorResId) return;
    var resSource = $('.res-row[data-value="' + errorResId + '"]').attr('data-source');
    var resMIME = $('.res-row[data-value="' + errorResId + '"]').attr('data-mime');
    if ($.inArray(resMIME.toLowerCase(), ['audio', 'video']) != -1) {
        // 视频音频
        noticeTextContent = '目前仅支持 mp4 格式的视频和 mp3 格式的音频，该资源因格式问题，无法在线预览';
        if (userId === createrId) {
            if (resSource === 'CCP') {
                noticeTextContent += '，请联系教学包的作者';
            } else {
                noticeTextContent += '，请按照要求上传';
            }
        } else {
            noticeTextContent += '，请联系老师';
        }
    } else {
        noticeTextContent = '该资源不能预览，请下载后查看';
    }
    // 播放视频是发生错误
    confirms('提示', noticeTextContent, '', '', '', 'alert');
}

$(document).on('click', '.down-triangle-box, .operation ul', function (e) {
    // 阻止资源悬浮菜单的点击事件继续传播
    e.stopPropagation();
});
var videoDuration = $('.video-duration');
$(document).bind('webkitfullscreenchange mozfullscreenchange fullscreenchange', function (e) {
    var state = document.fullScreen || document.mozFullScreen || document.webkitIsFullScreen;
    if (state) {
        videoDuration.attr('class', 'video-duration fullscreen').appendTo($('#mep_0 .mejs__controls'));
    } else {
        videoDuration.attr('class', 'video-duration unfullscreen').appendTo($('.preview-video'));
    }
});

// 按照分组查看资源，已发布的数量
var resGroups = $('.res-row-box');
for (var i = 0; i < resGroups.length; i++) {
    var resource = resGroups.eq(i).find('.res-row');
    var releaseCount = 0;
    for (var j = 0; j < resource.length; j++) {
        if (resource.eq(j).attr('data-release-status') === 'Y') {
            releaseCount++;
        }
    }
    if (releaseCount > 1) {
        resGroups.eq(i).find('.res-row[data-release-status="Y"]').addClass('drag-res-row')
            .find('.manual-order-drag-res-button').addClass('manual-move-enable').removeClass('manual-move-disable');
    }
    resGroups.eq(i).children('.res-row-title').children('.release-count').text(releaseCount);
}

// 资源的移动
var resManualOrder = false;
var parentElement = null;
var movingElement = null;
var placeholderElement = null;

var mouseDownOffset = 0; // 拖动时，鼠标在目标上的偏移
var lastPositionIndex = -9;
var crossSiblingsCount = 0; // 不可见的元素，数量
var minPositionIndex = 0; // 在可见的同级元素列表中，最小可到达的位置
var childrenCount = 0;

var isDrop = true;

var dragResGroupId = ''; // 更改资源顺序的分组 id

var manualOrderGroup = false; // 调整了组顺序
var manualOrderResGroup = [];    // 调整了组内顺序

var requestCount = 0;
var dragOverGroupId = ''; // 被拖动资源所属分组的 id

var emptyRes = $('<div class="res-row"></div>').css({
    'width': '900px',
    'height': '60px'
});
var emptyGroup = $('<div class="res-row-box"></div>').css({
    'height': '30px'
});

// 拖动资源
var resRow = document.querySelectorAll('.res-row');
var resRowArray = Array.prototype.slice.call(resRow, 0);
resRowArray.forEach(function (resRow, index) {
    // resRow.setAttribute('draggable', 'true');
    if (resRow.classList.contains('drag-res-row')) {
        resRow.addEventListener('dragstart', function (event) {
            resDragStart(event, this);
        });
        resRow.addEventListener('drag', function (event) {
            stopPropagation(event);
        });
        resRow.addEventListener('dragend', function (event) {
            resDragEnd(event, this);
        });
    } else {
        resRow.addEventListener('dragstart', function (event) {
            event.preventDefault();
            event.stopPropagation();
        });
    }
});

// 资源放置区域
var hideDiv = document.querySelectorAll('.hide-div');
var hideDivArray = Array.prototype.slice.call(hideDiv, 0);
hideDivArray.forEach(function (hideDiv, index) {
    hideDiv.addEventListener('dragover', function (event) {
        groupDragOver(event, this);
    });
    hideDiv.addEventListener('drop', function (event) {
        groupDrop(event, this);
    });
});

// 拖动分组
var groups = document.querySelectorAll('.res-row-box');
var groupsArray = Array.prototype.slice.call(groups, 0);
groupsArray.forEach(function (group, index) {
    // group.setAttribute('draggable', 'true');
    if (group.classList.contains('drag-res-box')) {
        group.addEventListener('dragstart', function (event) {
            groupDragStart(event, this);
        });
        group.addEventListener('dragend', function (event) {
            groupDragEnd(event, this);
        });
    } else {
        group.addEventListener('dragstart', function (event) {
            event.stopPropagation();
            event.preventDefault();
        });
    }
});

// 分组放置区域
document.querySelector('#res-list-box').addEventListener('dragover', function (event) {
    groupBoxDragOver(event, this);
});

// 拖动资源
function resDragStart(event, _this) {
    if (!resManualOrder) {
        event.preventDefault();
        return;
    }
    event.stopPropagation();
    event.dataTransfer.setData('text', '');

    mouseDownOffset = event.clientY - _this.getBoundingClientRect().top;

    movingElement = $(_this);
    parentElement = movingElement.parent();
    dragResGroupId = movingElement.parents('.res-row-box').attr('data-id');
    placeholderElement = emptyRes;
    movingElement.addClass('moving');
    dragOverGroupId = movingElement.parents('.res-row-box').attr('data-id');

    childrenCount = parentElement.find('.res-row').length;
    crossSiblingsCount = childrenCount - parentElement.find('.drag-res-row').length;
    minPositionIndex = 0;

    isDrop = false;
}
function groupDragOver(event, _this) {
    var dropEnable = movingElement.hasClass('res-row') && $(_this).hasClass('hide-div') && $(_this).parents('.res-row-box').attr('data-id') == dragOverGroupId
    mouseMove(event, dropEnable, function (targetOnContainerOffset) {
        return Math.round(targetOnContainerOffset / 102);
    });
}
function resDragEnd(event, _this) {
    event.stopPropagation();
    if (lastPositionIndex != -9) {
        placeholderElement.replaceWith(movingElement);
    }
    movingElement.removeClass('moving');
    if ($.inArray(dragResGroupId, manualOrderResGroup) == -1) {
        manualOrderResGroup.push(dragResGroupId);
    }
    lastPositionIndex = -9;
    isDrop = true;
}
// 阻止 firefox 打开链接
function groupDrop(event, _this) {
    event.preventDefault();
}

// 拖拽分组
function groupDragStart(event, _this) {
    if (!resManualOrder) {
        event.preventDefault();
        return;
    }
    event.dataTransfer.setData('text', '');

    movingElement = $(_this);
    parentElement = movingElement.parent();
    placeholderElement = emptyGroup;
    movingElement.addClass('moving');


    mouseDownOffset = event.clientY - _this.getBoundingClientRect().top;
    childrenCount = parentElement.children('div').length;
    crossSiblingsCount = parentElement.find('.book-box').length;
    minPositionIndex = 1;

    isDrop = false;

    movingElement.find('.hide-div').hide().attr('data-status', 'N');
    switchButtonStyle(false);
}
function groupDragEnd(event, _this) {
    if (lastPositionIndex != -9) {
        placeholderElement.replaceWith(movingElement);
    }
    movingElement.removeClass('moving');
    isDrop = true;
    manualOrderGroup = true;
    lastPositionIndex = -9;
}
function groupBoxDragOver(event, _this) {
    var dropEnable = movingElement.hasClass('res-row-box') && $(_this).attr('id') === 'res-list-box';
    var initLastPositionIndex = mouseMove(event, dropEnable, function (targetOnContainerOffset) {
        return Math.round(targetOnContainerOffset / 60);
    });
    if (initLastPositionIndex) {
        $('.hide-div').hide().attr('data-status', 'N');
        lastPositionIndex = -1;
    }
}
function stopPropagation(event) {
    event.stopPropagation();
}
/**
 * @param event [Event Object] dragOver 中的事件对象
 * @param dropEnable [Boolean] 是否可放置(鼠标样式)
 * @param computePositionIndexFunc [Function] 计算拖动元素放置的索引，接受一个参数：拖动目标相对于父元素的 top 偏移
 */
function mouseMove(event, dropEnable, computePositionIndexFunc) {
    if (dropEnable && resManualOrder) {
        event.preventDefault();
    } else {
        return;
    }
    event.stopPropagation();
    if (!parentElement || !movingElement || !placeholderElement) {
        return;
    }
    var mouseOnContainerOffset = event.clientY - parentElement[0].getBoundingClientRect().top;
    var targetOnContainerOffset = mouseOnContainerOffset - mouseDownOffset; // 拖动目标在父元素上的偏移
    var livePositionIndex = computePositionIndexFunc(targetOnContainerOffset);
    // 控制拖动范围
    livePositionIndex = livePositionIndex > minPositionIndex ? livePositionIndex : minPositionIndex;
    livePositionIndex = livePositionIndex >= childrenCount - 1 ? childrenCount - 1 : livePositionIndex;
    livePositionIndex += crossSiblingsCount;
    // 初始位置索引
    var initLastPositionIndex = false;
    if (lastPositionIndex === -9) {
        lastPositionIndex = livePositionIndex;
        movingElement.replaceWith(placeholderElement);
        initLastPositionIndex = true;
    }
    // 位置发生变化
    if (lastPositionIndex != livePositionIndex) {
        var replaceTarget = parentElement.children('div').eq(livePositionIndex); // 目标位置的元素
        if (replaceTarget.length === 0) return;
        var top = parseInt(replaceTarget.css('top'));
        var height = replaceTarget[0].offsetHeight;
        var topOffset = livePositionIndex > lastPositionIndex ? -(height) : height;
        replaceTarget.css({
            'position': 'relative'
        }).animate({
            'top': !top || top === 0 ? topOffset : top + topOffset
        }, 100, function () {
            replaceTarget.css({
                'position': '',
                'top': ''
            });
            if (isDrop) return;
            placeholderElement.remove();
            if (livePositionIndex === 0) {
                parentElement.prepend(placeholderElement);
            } else {
                parentElement.children('div').eq(livePositionIndex - 1).after(placeholderElement);
            }
        });
        lastPositionIndex = livePositionIndex;
    }
    return initLastPositionIndex;
}

/**
* 进入/退出手动调序
* @param action enter 进入， exit 退出
*/
function switchManualOrderView(action) {
    if (action === 'enter') {
        resManualOrder = true;
        $('.manual-order').show();
        $('.manual-order-hide-part').hide();
        $('.res-row').removeClass('res-row-open-enable');
        $('.res-row, .res-row-box').attr('draggable', 'true');
        $('.res-name').parent().removeClass('overflow-ellipsis').css('width', '790px');
    } else if (action === 'exit') {
        resManualOrder = false;
        $('.manual-order').hide();
        $('.res-row').addClass('res-row-open-enable');
        $('.manual-order-hide-part').show();
        $('.res-row, .res-row-box').attr('draggable', 'false');
        $('.res-name').parent().addClass('overflow-ellipsis').css('width', '520px');
    }
}

