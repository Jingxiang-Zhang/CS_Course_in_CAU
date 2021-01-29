using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityStandardAssets.Vehicles.Car;

public class Board : MonoBehaviour {
	// Use this for initialization
	void Start () {
	}
    public void SetGazedAt(bool gazedAt) {

        Text text;
        text = this.transform.Find("Canvas/Text").GetComponent<Text>();
        text.text = "让我们出发吧！";
        GameObject Car = GameObject.Find("Car");
        MyCar ca = Car.GetComponent<MyCar>();
        ca.setStart();

        GameObject Canvas = GameObject.Find("Canvas");
        GUIcontroller Controller = Canvas.GetComponent<GUIcontroller>();
        Controller.setFlush((int)(1 / Time.deltaTime));

    }
    // Update is called once per frame
    void Update () {
		
	}
}
