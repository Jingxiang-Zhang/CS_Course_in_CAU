using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIcontroller : MonoBehaviour {
    Image imageH;
    Image imageQ;
    Image imageR;
    Image imageE;
    Text text;
    GameObject textobj;
    // Use this for initialization
    public GameObject Camera;
    public GameObject Canvas;
    public GameObject Player;
    public GameObject Car;
    void Start () {
        imageH = this.transform.Find("Button_H").GetComponent<Image>();
        imageQ = this.transform.Find("Button_Q").GetComponent<Image>();
        imageR = this.transform.Find("Button_R").GetComponent<Image>();
        imageE = this.transform.Find("Button_E").GetComponent<Image>();
        imageR.color = Color.gray;
        imageH.color = Color.gray;
        imageE.color = Color.gray;
        imageQ.color = Color.gray;
        text = this.transform.Find("Text").GetComponent<Text>();
        textobj = this.transform.Find("Text").gameObject;
    }
    void ColorRecovery()
    {
        imageR.color = Color.gray;
        imageH.color = Color.gray;
        imageE.color = Color.gray;
        imageQ.color = Color.gray;
    }
    int times = 0;
    int last = -1;
    // Update is called once per frame
    bool firstTimes = true;
    int Flush = 25;
    public void setFlush(int i)
    {
        Flush = 25;
    }

    void Update () {
        float x = Camera.transform.eulerAngles.x;
        if (firstTimes)
        {
            float Xt = Player.transform.position.x;
            float Zt = Player.transform.position.z;
            float Yro = Car.transform.eulerAngles.y;
            Zt = Zt + (float)(40 * System.Math.Cos(Yro / 180 * System.Math.PI));
            Xt = Xt + (float)(40 * System.Math.Sin(Yro / 180 * System.Math.PI));
            this.transform.position = new Vector3(Xt, 20f, Zt);
            this.transform.rotation = Quaternion.Euler(0.0f, Yro, 0.0f);
            //  this
            Debug.Log(Xt.ToString() + "    " + Zt.ToString());
            firstTimes = false;
        }
        //Debug.Log(x.ToString());
        if (x <= 350 && x >= 343)
        {
            if (last != 0)
            {
                last = 0;
                times = 0;
                ColorRecovery();
                imageR.color = Color.black;
                textobj.SetActive(true);
                text.text = "是否返回场景：2";
            }
            else if (last == 0 && times <= (int)(3 * Flush))
            {
                times++;
            }
            else
            {
                times = 0;
                Time.timeScale = 1;
                firstTimes = true;
                Canvas.SetActive(false);
            }
            if (times % Flush == 0)
            {
                text.text = "是否返回场景：" + (3 - times / Flush).ToString() + "";
            }
        }
        else if ((x <= 360 && x >= 353) || x <= 1)
        {
            if (last != 1)
            {
                last = 1;
                times = 0;
                ColorRecovery();
                imageQ.color = Color.black;
                textobj.SetActive(true);
                text.text = "是否退出：2";
            }
            else if (last == 1 && times <= (int)(3 * Flush))
            {
                times++;
            }
            else
            {
                Application.Quit();
            }
            if (times % Flush == 0)
            {
                text.text = "是否退出：" + (3 - times / Flush).ToString() + "";
            }
        }
        else if (x <= 339 && x >= 332)
        {
            if (last != 2)
            {
                last = 2;
                times = 0;
                ColorRecovery();
                imageE.color = Color.black;
                textobj.SetActive(true);
                text.text = "张靖祥，计算机172";
            } 
        }
        else if (x <= 329 && x >= 323)
        {
            if (last != 3)
            {
                last = 3;
                times = 0;
                ColorRecovery();
                imageH.color = Color.black;
                textobj.SetActive(true);
                text.text = "抬头，即可打开菜单";
            }
        }
        else
        {
            ColorRecovery();
            last = -1;
            textobj.SetActive(false);
            times = 0;
        }
 
    }
}
