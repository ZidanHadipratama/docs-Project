https://www.bugbountytraining.com/fastfoodhackings/index.php?act=login

https://www.bugbountytraining.com/yourprofile.php

https://www.bugbountytraining.com/fastfoodhackings/confirmed.php?order_id=NDIwNjk=






// Done

GET /fastfoodhackings/book.php HTTP/1.1

<script>
    function submitBooking() {
        var userFN = document.getElementById("fname").value;
        var dateBook = document.getElementById("date").value;
        var userEmail = document.getElementById("email").value;

        var req = new XMLHttpRequest();
        req.addEventListener("load", htmlResp);
        req.open("POST", "api/book.php?battleofthehackers=no");
        req.setRequestHeader("Anti-CSRF", "bGFrTsypaRAXzeaXtxYcF3HmGVHBbaEoL/UT6hokcAFBEa+1KgDGM3f2zzUuQm3n/3FjCnQj+qs4PSsjdSN4VsHgoZBSqw6GeaicOuyKc63BtiFU0+Sat4zDpUmCSZPf");
        req.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;charset=UTF-8");
        req.withCredentials = true;
        req.send("email=" + userEmail + "&date=" + dateBook + "&userFN=" + userFN);


        function htmlResp() {
            var strHTML = this.responseText;
            if (strHTML.includes("Error:") == true) {
                alert(this.responseText);
            } else {
                alert("Your booking submission has been received and you will be notified via email if accepted!");
                top.location.href = '/fastfoodhackings/confirmed.php?order_id=' + btoa(this.responseText);
            }
        }
    }
</script>

// Done





// Done

POST /fastfoodhackings/api/book.php?battleofthehackers=no HTTP/1.1
Host: www.bugbountytraining.com
Connection: keep-alive
Content-Length: 38
sec-ch-ua: "Chromium";v="122", "Not(A:Brand";v="24", "Google Chrome";v="122"
Content-Type: application/x-www-form-urlencoded;charset=UTF-8
sec-ch-ua-mobile: ?0
Anti-CSRF: bGFrTsypaRAXzeaXtxYcF3HmGVHBbaEoL/UT6hokcAFBEa+1KgDGM3f2zzUuQm3n/3FjCnQj+qs4PSsjdSN4VsHgoZBSqw6GeaicOuyKc63BtiFU0+Sat4zDpUmCSZPf
User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36
sec-ch-ua-platform: "Linux"
Accept: */*
Origin: https://www.bugbountytraining.com
Sec-Fetch-Site: same-origin
Sec-Fetch-Mode: cors
Sec-Fetch-Dest: empty
Referer: https://www.bugbountytraining.com/fastfoodhackings/book.php
Accept-Encoding: gzip, deflate, br
Accept-Language: en-US,en;q=0.9

email=test&date=2024-04-18&userFN=test

HTTP/1.1 200 OK
Server: nginx/1.18.0 (Ubuntu)
Date: Wed, 03 Apr 2024 06:19:06 GMT
Content-Type: text/html; charset=UTF-8
Connection: keep-alive
Set-Cookie: bookingInfo=eyduYW1lJzondGVzdCcsICdkYXRlJzonMjAyNC0wNC0xOCcsICdlbWFpbCc6J3Rlc3QnfQ%3D%3D; expires=Mon, 08-Apr-2024 06:19:06 GMT; Max-Age=432000; path=/; HttpOnly
Content-Length: 5

42069

// Done








GET /fastfoodhackings/api/loader.php?f=/reviews.php HTTP/1.1
Host: www.bugbountytraining.com
Connection: keep-alive
sec-ch-ua: "Chromium";v="122", "Not(A:Brand";v="24", "Google Chrome";v="122"
sec-ch-ua-mobile: ?0
User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36
sec-ch-ua-platform: "Linux"
Accept: */*
Sec-Fetch-Site: same-origin
Sec-Fetch-Mode: cors
Sec-Fetch-Dest: empty
Referer: https://www.bugbountytraining.com/fastfoodhackings/locations.php
Accept-Encoding: gzip, deflate, br
Accept-Language: en-US,en;q=0.9


/*
const debuggerA = urlParams.get('debug');
if (debuggerA === null) { 
   
} else {
        var oReq = new XMLHttpRequest();
        oReq.addEventListener("load", reqListener);
        oReq.open("GET", "?f=/generate-credentials");
        oReq.send();

      function reqListener () {
        document.write(this.responseText);
      }
      
}*/









GET /fastfoodhackings/locations.php HTTP/1.1
Host: www.bugbountytraining.com
Connection: keep-alive
sec-ch-ua: "Chromium";v="122", "Not(A:Brand";v="24", "Google Chrome";v="122"
sec-ch-ua-mobile: ?0
User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36
sec-ch-ua-platform: "Linux"
Accept: text/css,*/*;q=0.1
Sec-Fetch-Site: same-origin
Sec-Fetch-Mode: no-cors
Sec-Fetch-Dest: style
Referer: https://www.bugbountytraining.com/fastfoodhackings/locations.php
Accept-Encoding: gzip, deflate, br
Accept-Language: en-US,en;q=0.9

<script>
    $.get("https://ipinfo.io", function(response) {
        var userCountry = response.country;
        if (userCountry == "GB") {
            document.getElementById("ad").innerHTML = '<div class="alert alert-warning" role="alert"><i class="fab fa-adversal icon-2x text-red"></i> <a href="book.php?promoCode=UKONLY">UK promotion: Buy one meal get <u>two</u> free!</a></div>';
            document.getElementById("gmap").src = "https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d6738.972484852003!2d-1.7305805611669134!3d53.33275538645695!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x487a2b86abe63895%3A0x2c872aeb36297d4!2sBrough%20Ln%2C%20Hope%20Valley!5e0!3m2!1sen!2suk!4v1628522822227!5m2!1sen!2suk";
        } else {
            document.getElementById("gmap").src = "https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d15609.52149200314!2d-6.98960860473787!3d61.632818183680115!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x0%3A0x0!2zNjHCsDM3JzU3LjgiTiA2wrA1OCczOS40Ilc!5e0!3m2!1sen!2suk!4v1628523417848!5m2!1sen!2suk";
        }
    }, "jsonp");

    function getreviews() {
        var oReq = new XMLHttpRequest();
        oReq.addEventListener("load", reqListener);
        oReq.open("GET", "api/loader.php?f=/reviews.php");
        oReq.send();
        document.getElementById("noinvs").style.display = "block";

        function reqListener() {
            document.getElementById("reviews").innerHTML = this.responseText;
        }
    }
</script>







<script src="https://bugbountytraining.com/assets/js/custom-script.js"></script>
<script src="https://bugbountytraining.com/assets/js/script.min.js"></script>






https://www.bugbountytraining.com/fastfoodhackings/robots.txt

Disallow: /admin
Disallow: /go

https://www.bugbountytraining.com/fastfoodhackings/go.php




https://www.bugbountytraining.com/fastfoodhackings/index.php?from=/admin.php&type=1#redir=/admin.php

var adToken = "c0f22cf8-96ea-4fbb-8805-ee4246095031";
