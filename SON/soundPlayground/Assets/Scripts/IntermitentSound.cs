
// '1' empieza la reproducción del sonido intermitente
// '2' lo para

using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class IntermitentSound : MonoBehaviour {
    [SerializeField]
    private List<AudioSource> _Speakers;  // audio source asosicada a la entidad
    [Range(0f, 1f )]
    public float minVol, maxVol, SourceVol;  // volumenes máximo y mínimo establecidos y volumen origintal del source
    public int poliphony;// numero maximo de sonidos que se pueden generar a la vez
    [Range(0f, 30f )]
    public float minTime, maxTime;  // intervalo temporal de lanzamiento
    [Range(0, 50)]
    public int distRand, maxDist;   // 
    [Range(0f, 1.1f )]
    public float spatialBlend;
    public AudioClip[] pcmData;
    public bool enablePlayMode;

    private Queue<AudioSource> availableSources;
    
    private bool started = false;

    void Start() {

        Debug.Log("IntermitentSound Start");

        _Speakers = new List<AudioSource>();
        availableSources = new Queue<AudioSource>(); 

        for(int i = 0; i < poliphony; i++)
        {
            AudioSource source = gameObject.AddComponent<AudioSource>();
            source.playOnAwake = false;
            source.loop = false;
            _Speakers.Add(source);
            availableSources.Enqueue(source);
        }       

        Debug.Log("IntermitentSound Start finished, sources:" + _Speakers.Count);


        foreach (var speaker in _Speakers) {
            speaker.playOnAwake = false;
            speaker.volume = 0.1f;
            speaker.loop = false;

        }
    }

    // Update is called once per frame
    void Update() {


        if(enablePlayMode && !started)
        {
            started = true;
            StartAllSounds();
            Debug.LogWarning("Threshold overcome: All sounds started.");
        }

        if(!enablePlayMode && started)
        {
            started = false;
            StopAllSounds();
            Debug.LogWarning("Threshold not overcome: All sounds stopped.");
        }
    }



    void StartAllSounds()
    {
        Debug.Log("Starting all Sounds");
        for (int i = 0; i < _Speakers.Count; i++)
        {
            StartCoroutine(PlaySoundWithDelay(_Speakers[i]));
        }
    }

    IEnumerator PlaySoundWithDelay(AudioSource source)
    {
        while (enablePlayMode)
        {
            float waitTime = Random.Range(minTime, maxTime);
            Debug.Log("Wait time for source "+ source + ": " + waitTime);
            yield return new WaitForSeconds(waitTime);  // Espera tiempo aleatorio entre cada sonido

            PlaySound();
        }

        yield return null;
    }

    void PlaySound() {

        if(availableSources.Count > 0){
            AudioSource currentSource = availableSources.Dequeue();
            SetSourceProperties(currentSource, pcmData[Random.Range(0, pcmData.Length)], minVol, maxVol, distRand, maxDist, spatialBlend);
            currentSource.Play();
            Debug.Log("Source " + currentSource + "with clip " + currentSource.clip + " playing");
            StartCoroutine(ReturnSourceToQueue(currentSource));
        }
    }

    IEnumerator ReturnSourceToQueue(AudioSource source) {
        yield return new WaitForSeconds(source.clip.length);
        availableSources.Enqueue(source);

        //End coroutine
        yield return null;
    }

    public void SetSourceProperties(AudioSource source, AudioClip audioData, float minVol, float maxVol,
                                    int minDist, int maxDist, float SpatialBlend) {
        source.clip = audioData;
        source.volume = Mathf.Clamp(SourceVol + Random.Range(minVol, maxVol), minVol, maxVol);
        source.maxDistance = maxDist - Random.Range(0f, distRand);
        source.spatialBlend = spatialBlend;
    }

    void StopAllSounds()
    {
        enablePlayMode = false;
        StopAllCoroutines();
        foreach (var speaker in _Speakers)
        {
            speaker.Stop();
            if (!availableSources.Contains(speaker))
            {
                availableSources.Enqueue(speaker);  // Asegurar que las fuentes activas se reinsertan en la cola
            }
        }
    }
}    
    