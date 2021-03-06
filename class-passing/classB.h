#include <iostream>
#include <string>
#include <cstring>
// #include <typeinfo>
#include "mex.h"
#include "../class_handle.hpp"
#include "classA.h"

using namespace std;

// The class that we are interfacing to
class classB
{
public:
    
    double y;
    
    // constructor
    classB () {y = 0;}
    
    void useclassA (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) 
    {
        double *ptype;
        size_t mrows, ncols;

        /* check for proper number of arguments */
        if(nrhs!=3)
            mexErrMsgIdAndTxt( "MFEMM:fpproc:invalidNumInputs",
                               "One input required.");
        else if(nlhs != 0)
            mexErrMsgIdAndTxt( "MFEMM:fpproc:maxlhs",
                               "Wrong number of output arguments.");

        /*  get the dimensions of the matrix input x */
        mrows = mxGetM(prhs[2]);
        ncols = mxGetN(prhs[2]);
        
                /*  get the dimensions of the matrix input x */
        mrows = mxGetM(prhs[2]);
        ncols = mxGetN(prhs[2]);
        
        // check dimensions are allowed
        if((mrows!=1) | (ncols!=1))
        {
            mexErrMsgIdAndTxt( "MFEMM:fpproc:invalidSizeInputs",
                               "object handle must be a scalar.");
        }
        
        // get the pointer to the other class
        classA * classA_instance = convertMat2Ptr<classA>(prhs[2]);

        mexPrintf ("y for this is %f, x for other is: %f\n", y, classA_instance->x);
    }
    
    void sety (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
    {
        double *ptype;
        size_t mrows, ncols;

        /* check for proper number of arguments */
        if(nrhs!=3)
            mexErrMsgIdAndTxt( "MFEMM:fpproc:invalidNumInputs",
                               "One input required.");
        else if(nlhs != 0)
            mexErrMsgIdAndTxt( "MFEMM:fpproc:maxlhs",
                               "Wrong number of output arguments.");

        /*  get the dimensions of the matrix input x */
        mrows = mxGetM(prhs[2]);
        ncols = mxGetN(prhs[2]);
        
        // check dimensions are allowed
        if((mrows!=1) | (ncols!=1))
        {
            mexErrMsgIdAndTxt( "MFEMM:fpproc:invalidSizeInputs",
                               "x must be a scalar.");
        }

        // get a pointer to the actual data
        ptype = mxGetPr(prhs[2]);

        // cast the value in the matlab matrix to an integer
        y = ptype[0];
    }
    
    double printy ()
    {
        mexPrintf ("x for this class is: %f\n", y);
    }
    
private:
};
