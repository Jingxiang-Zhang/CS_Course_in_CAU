using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Itinerary : MonoBehaviour {
    private GameObject Car;
    public GameObject Canvas;
    public GameObject Camera;
    // private float CameraX;
    //private float CameraY;
    // private float CameraZ;
    // Use this for initialization
    void Awake()
    {

    }
    void Start () {
        Car=GameObject.Find("Car");
    }
    int i = 0;
    int flag = -1;
    // Update is called once per frame
    void Update () {
        if (Camera.transform.eulerAngles.x>=275 && Camera.transform.eulerAngles.x < 300)
        {
            Canvas.SetActive(true);
            Time.timeScale = 0;
        }


        float rotation = Car.transform.eulerAngles.y;
        double x = 5 * System.Math.Sin(rotation / 180 * System.Math.PI);
        double y = 5 * System.Math.Cos(rotation / 180 * System.Math.PI);
        i++;
        if (i % 30 == 0)
        {
            i = 0;
           /* Debug.Log(rotation+"  "+x.ToString()+"  "+ Car.transform.position.x.ToString()+ "  "+
                y.ToString() + "  " + Car.transform.position.z.ToString());*/
        }
        
        this.transform.position = new Vector3(Car.transform.position.x - (float)x,
                                            Car.transform.position.y + 2,
                                            Car.transform.position.z - (float)y);
        float Yro = Car.transform.eulerAngles.y;
        this.transform.rotation = Quaternion.Euler(5f, Yro, 0.0f);
        
    }
}
