import router from '@ohos.router';

var numbs = 0;
var code = 0;
var inputVal = 0;
export default {
    data: {
        pincode: router.getParams().pinCode,
        isShow:false,
        isTimes:3,
    },
    onInit() {
        code = router.getParams().pinCode;
        callNativeHandler("EVENT_CONFIRM", "2");
    },
    onChange(e){ 
        inputVal = e.value; 
    }, 
    onConfirm() {
        numbs = numbs + 1;
        if(numbs <= 3){
            console.info('click confirm numbs < 3 ');
            if(code == inputVal){
                console.info('click confirm code == inputVal');
                callNativeHandler("EVENT_INPUT", "0");
            }else{
                if(numbs == 3){
                    console.info('click confirm code != inputVal and numbs == 3');
                    callNativeHandler("EVENT_CONFIRM", "1");
                }
                console.info('click confirm code != inputVal');
                this.isShow = true;
                this.isTimes = 3 - numbs;
            }
        }else{
            console.info('click confirm numbs > 3 ');
            callNativeHandler("EVENT_CONFIRM", "1");
        }       
    },
    onCancel() {
        console.info('click cancel');
        callNativeHandler("EVENT_CONFIRM", "1");
    }
}