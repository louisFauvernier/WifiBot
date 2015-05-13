#include "camera.h"

Camera::Camera()
{
        fn_haar = "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml";
        haar_cascade.load(fn_haar);
}

void Camera::setVideoOutput(ViewerGl *viewer)
{
    this->viewer = viewer;
}

void Camera::start()
{
    if( !mCapture.isOpened() )
            if( !mCapture.open( 0 ) )
                return;

    startTimer(0);
}

void Camera::stop()
{

}

void Camera::timerEvent(QTimerEvent *event)
{



            mCapture >> frame;
            // Clone the current frame:
            //original = frame.clone();
            // Convert the current frame to grayscale:

            cvtColor(frame, gray, CV_BGR2GRAY);
            // Find the faces in the frame:

            haar_cascade.detectMultiScale(gray, faces, 1.2, 2, 0|CV_HAAR_SCALE_IMAGE,Size(100, 100));
            // At this point you have the position of the faces in
            // faces. Now we'll get the faces, make a prediction and
            // annotate it in the video. Cool or what?
            for(int i = 0; i < faces.size(); i++) {
                // Process face by face:
                face_i = faces[i];
                // Crop the face from the image. So simple with OpenCV C++:
                face = gray(face_i);
                // Resizing the face is necessary for Eigenfaces and Fisherfaces. You can easily
                // verify this, by reading through the face recognition tutorial coming with OpenCV.
                // Resizing IS NOT NEEDED for Local Binary Patterns Histograms, so preparing the
                // input data really depends on the algorithm used.
                //
                // I strongly encourage you to play around with the algorithms. See which work best
                // in your scenario, LBPH should always be a contender for robust face recognition.
                //
                // Since I am showing the Fisherfaces algorithm here, I also show how to resize the
                // face you have just found:
                //Mat face_resized;
                //cv::resize(face, face_resized, Size(im_width, im_height), 1.0, 1.0, INTER_CUBIC);
                // Now perform the prediction, see how easy that is:
                //int prediction = model->predict(face_resized);
                // And finally write all we've found out to the original image!
                // First of all draw a green rectangle around the detected face:
                rectangle(frame, face_i, CV_RGB(0, 255,0), 2);
                // Create the text we will annotate the box with:
                //string box_text = format("Prediction = %d", prediction);
                // Calculate the position for annotated text (make sure we don't
                // put illegal values in there):
                //int pos_x = std::max(face_i.tl().x - 10, 0);
                //int pos_y = std::max(face_i.tl().y - 10, 0);
                // And now put it into the image:
                //putText(original, box_text, Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
            }


    // Show the image
    viewer->showImage( frame );
}