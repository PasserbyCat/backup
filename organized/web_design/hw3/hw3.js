var state = ["Alabama","Alaska","Arizona","Arkansas","California",
"Colorado","Connecticut","Delaware","Florida","Georgia",
"Hawaii","Idaho","Illinois","Indiana","Iowa",
"Kansas","Kentucky","Louisiana","Maine","Maryland",
"Massachusetts","Michigan","Minnesota","Mississippi","Missouri",
"Montana","Nebraska","Nevada","New Hampshire","New Jersey",
"New Mexico","New York","North Carolina","North Dakota","Ohio",
"Oklahoma","Oregon","Pennsylvania","Rhode Island","South Carolina",
"South Dakota","Tennessee","Texas","Utah","Vermont",
"Virginia","Washington","WestVirginia","Wisconsin","Wyoming"];
var height=[2.291288,3.834058,3.929377,6.236986,6.637771,7.355270,8.027453,
8.537564,10.860018,11.456439,12.424975,12.614278,12.775367,13.044922,
13.297368,13.349157,13.896043,14.501034,15.407790,15.454449,15.630099,
15.890249,16.976749,18.264994,19.437592,19.904271,21.167192,22.366046,
22.766642,24.894377,25.093027,28.635118,29.250641,31.477135,31.620405,
32.718802,36.734861,36.847931,38.527912,41.487950,48.725148,53.593376,
57.271022,64.993615,68.762272,87.326342,102.861557,168.611417,293.622751];
var merge =[
[-15,-29],
[-17,-26],
[-14,-16],
[-13,-32],
[-35,-44],
[-36,-46],
[-7,-38],
[-19,-41],
[-49,1],
[-21,-30],
[-37,6],
[-4,-42],
[-48,8],
[-34,-45],
[-22,-28],
[-27,2],
[-3,-31],
[-6,-43],
[-12,3],
[-1,-18],
[-50,11],
[-20,17],
[-8,20],
[5,7],
[-23,9],
[16,19],
[-24,-40],
[4,15],
[-47,10],
[-25,12],
[-10,18],
[-2,27],
[21,29],
[24,26],
[-11,25],
[-5,28],
[30,31],
[-39,33],
[-9,-33],
[13,14],
[23,32],
[22,36],
[35,40],
[41,42],
[37,38],
[34,43],
[39,44],
[45,46],
[47,48]];
function progress(){
	var dis = document.form.dis.value;
	var target = document.form.target.value;
	var output=""


    /*----------------- Your Code Start-------------*/



    /*----------------- Your Code End --------------*/
    document.getElementById('out').innerHTML= output;
}
