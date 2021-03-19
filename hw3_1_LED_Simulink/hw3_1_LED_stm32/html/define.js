function CodeDefine() { 
this.def = new Array();
this.def["hw3_1_LED_B"] = {file: "hw3_1_LED_c.html",line:35,type:"var"};
this.def["hw3_1_LED_DW"] = {file: "hw3_1_LED_c.html",line:38,type:"var"};
this.def["hw3_1_LED_M_"] = {file: "hw3_1_LED_c.html",line:41,type:"var"};
this.def["hw3_1_LED_M"] = {file: "hw3_1_LED_c.html",line:42,type:"var"};
this.def["hw3_1_LED_step"] = {file: "hw3_1_LED_c.html",line:45,type:"fcn"};
this.def["hw3_1_LED_initialize"] = {file: "hw3_1_LED_c.html",line:67,type:"fcn"};
this.def["B_hw3_1_LED"] = {file: "hw3_1_LED_h.html",line:54,type:"type"};
this.def["DW_hw3_1_LED"] = {file: "hw3_1_LED_h.html",line:59,type:"type"};
this.def["RT_MODEL_hw3_1_LED"] = {file: "hw3_1_LED_types_h.html",line:37,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:79,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:80,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:81,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:82,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:93,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:98,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:103,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:110,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:117,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:124,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:131,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:138,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:145,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:163,type:"type"};
this.def["main.c:OverrunFlags"] = {file: "main_c.html",line:38,type:"var"};
this.def["main.c:autoReloadTimerLoopVal_S"] = {file: "main_c.html",line:41,type:"var"};
this.def["remainAutoReloadTimerLoopVal_S"] = {file: "main_c.html",line:44,type:"var"};
this.def["main"] = {file: "main_c.html",line:52,type:"fcn"};
this.def["SysTick_Handler"] = {file: "stm32xxxx_it_c.html",line:34,type:"fcn"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["hw3_1_LED_c.html"] = "../hw3_1_LED.c";
	this.html2Root["hw3_1_LED_c.html"] = "hw3_1_LED_c.html";
	this.html2SrcPath["hw3_1_LED_h.html"] = "../hw3_1_LED.h";
	this.html2Root["hw3_1_LED_h.html"] = "hw3_1_LED_h.html";
	this.html2SrcPath["hw3_1_LED_private_h.html"] = "../hw3_1_LED_private.h";
	this.html2Root["hw3_1_LED_private_h.html"] = "hw3_1_LED_private_h.html";
	this.html2SrcPath["hw3_1_LED_types_h.html"] = "../hw3_1_LED_types.h";
	this.html2Root["hw3_1_LED_types_h.html"] = "hw3_1_LED_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["STM32_Config_h.html"] = "../STM32_Config.h";
	this.html2Root["STM32_Config_h.html"] = "STM32_Config_h.html";
	this.html2SrcPath["hw3_1_LED_External_Functions_h.html"] = "../hw3_1_LED_External_Functions.h";
	this.html2Root["hw3_1_LED_External_Functions_h.html"] = "hw3_1_LED_External_Functions_h.html";
	this.html2SrcPath["main_c.html"] = "../main.c";
	this.html2Root["main_c.html"] = "main_c.html";
	this.html2SrcPath["stm32xxxx_it_c.html"] = "../stm32xxxx_it.c";
	this.html2Root["stm32xxxx_it_c.html"] = "stm32xxxx_it_c.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"hw3_1_LED_c.html","hw3_1_LED_h.html","hw3_1_LED_private_h.html","hw3_1_LED_types_h.html","rtwtypes_h.html","STM32_Config_h.html","hw3_1_LED_External_Functions_h.html","main_c.html","stm32xxxx_it_c.html"];
