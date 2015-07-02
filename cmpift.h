/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Copyright (c) 2006-2015 The Open Group                                    */
/*                                                                           */
/* Permission is hereby granted, free of charge, to any person obtaining a   */
/* copy of this software (the "Software"), to deal in the Software without   */
/* restriction, including without limitation the rights to use, copy,        */
/* modify, merge, publish, distribute, sublicense, and/or sell copies of     */
/* the Software, and to permit persons to whom the Software is furnished     */
/* to do so, subject to the following conditions:                            */
/*                                                                           */
/* The above copyright notice and this permission notice shall be included   */
/* in all copies or substantial portions of the Software.                    */
/*                                                                           */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   */
/* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.    */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY      */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT */
/* OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  */
/* THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                */
/*                                                                           */
/* ------------------------------------------------------------------------- */

/**
 * @file cmpift.h
 * @brief Defines the various CMPI structures and function tables;
 * all MIs should include this header.
 *
 * This header file belongs to the Technical Standard: Systems Management:
 * Common Manageability Programming Interface (CMPI) Issue 2 Version 1.
 *
 * This header file is provided as a convenience only. In the case of any
 * discrepancy between the header file and the Technical Standard
 * (incorporating any subsequent Technical Corrigenda), the Technical Standard
 * shall be definitive.
 */

#ifndef _CMPIFT_H_
#define _CMPIFT_H_

#include "cmpidt.h"
#include "cmpios.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup mi-factory
 * @{
 *   For details on how MI factory functions are used by an MB, including
 *   precedence in the presence of both generic and MI-specific factory
 *   functions, and extensibility,
 *   see Subclause 6.1 of the @ref ref-cmpi-standard "CMPI Standard".
 */

// DONE_AM Next function is already synced with spec.
/**
 @defgroup mi-factory-specific MI-specific MI factory function.

 <b>@ref CMPI_EXTERN_C CMPI\<mi-type\>MI* \<mi-name\>_Create_\<mi-type\>MI(
 const @ref CMPIBroker* mb, const @ref CMPIContext* ctx,
 @ref CMPIStatus* rc);</b>

 @ref mi-factory-specific "\<mi-name\>_Create_\<mi-type\>MI()" is an
 MI-specific factory function for an MI and is responsible for intializing the
 MI of type \<mi-type\> with the predefined name \<mi-name\>.

 \<mi-type>\ can be one of:
 @li Instance
 @li Association
 @li Property (**Deprecated**)
 @li Method
 @li Indication

 While this function executes, the MB will not call any other MI functions for
 this MI. This function will be called once for a specific MI, even if that MI
 services more than one namespace.

 This function shall be declared with the @ref CMPI_EXTERN_C modifier or
 an equivalent modifier; the name of this function shall be exported from the
 MI load library.

 @param mb Points to a CMPIBroker structure.
     This structure can be used throughout the life of this MI function group
     to invoke MB services.
 @param ctx Points to a CMPIContext object containing the context data
     for the invocation.
     This CMPIContext object contains the @ref CMPIInitNameSpace entry
     indicating the namespace for which this MI is to be initialized.
     If this MI services more than one namespace, the @ref CMPIInitNameSpace
     entry indicates one of those namespaces.
 @param [out] rc Points to a CMPIStatus structure that upon return shall
     have been updated with the function return status.
 @return @parblock
     If successful, a pointer to a valid CMPI\<mi-type\>MI structure
     (CMPIInstanceMI, CMPIAssociationMI, CMPIPropertyMI, CMPIMethodMI,
     CMPIIndicationMI) for the MI identified by \<mi-type\> and \<mi-name\>
     shall be returned, and the MB will consider this MI to be initialized
     (that is, functioning).

     If not successful, NULL shall be returned, and the MI identified by
     \<mi-type\> and \<mi-name\> is considered uninitialized (that is,
     malfunctioning) and will not be used by the MB. Specifically, the
     cleanup function for this MI (e.g. CMPIInstanceMIFT.cleanup()) will not be
     invoked by the MB in that case.
 @endparblock

 @par Errors
 The following @ref CMPIrc codes shall be used by the MI in the
 function return status:
 @li `CMPI_RC_OK` - Function successful.
 @li `CMPI_RC_ERR_FAILED` - Other error occurred.
 @li `CMPI_RC_ERR_NOT_SUPPORTED` - MI type not supported for this MI name.
 @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.

 CMPI 2.1 documented these return codes for the first time. For backwards
 compatibility, MBs conforming to CMPI 2.1 that use MIs conforming to prior
 CMPI releases shall tolerate other uses of these return codes as well as
 additional return codes.
*/

// DONE_AM Next function is already synced with spec.
/**
 @defgroup mi-factory-generic Generic MI factory function.

 <b>@ref CMPI_EXTERN_C CMPI\<mi-type\>MI* _Generic_Create_\<mi-type\>MI(
 const @ref CMPIBroker* mb, const @ref CMPIContext* ctx, const char* miName,
 @ref CMPIStatus* rc);</b>

 @ref mi-factory-generic "_Generic_Create_\<mi-type\>MI()" is a generic factory
 function for an MI and is responsible for intializing the MI of type
 \<mi-type>\ with the name passed in @p miName.

 \<mi-type>\ can be one of:
 @li Instance
 @li Association
 @li Property (**Deprecated**)
 @li Method
 @li Indication

 While this function executes, the MB will not call any other MI functions for
 this MI. This function will be called once for a specific MI, even if that MI
 services more than one namespace.

 This function shall be declared with the @ref CMPI_EXTERN_C modifier or
 an equivalent modifier; the name of this function shall be exported from the
 MI load library.

 @param mb Points to a CMPIBroker structure.
     This structure can be used throughout the life of this MI function group
     to invoke MB services.
 @param ctx Points to a CMPIContext object containing the context data
     for the invocation.
     This CMPIContext object contains the @ref CMPIInitNameSpace entry
     indicating the namespace for which this MI is to be initialized.
     If this MI services more than one namespace, the @ref CMPIInitNameSpace
     entry indicates one of those namespaces.
 @param miName Points to a string containing the name of the MI to be
     initialized.
 @param [out] rc Points to a CMPIStatus structure that upon return shall
     have been updated with the function return status.
 @return @parblock
     If successful, a pointer to a valid CMPI\<mi-type\>MI structure
     (CMPIInstanceMI, CMPIAssociationMI, CMPIPropertyMI, CMPIMethodMI,
     CMPIIndicationMI) for the MI identified by \<mi-type\> and @p miName shall
     be returned, and the MB will consider this MI to be initialized (that is,
     functioning).

     If not successful, NULL shall be returned, and the MI identified by
     \<mi-type\> and @p miName is considered uninitialized (that is,
     malfunctioning) and will not be used by the MB. Specifically, the
     cleanup function for this MI (e.g. CMPIInstanceMIFT.cleanup()) will not be
     invoked by the MB in that case.
 @endparblock

 @par Errors
 The following @ref CMPIrc codes shall be used by the MI in the
 function return status:
 @li `CMPI_RC_OK` - Function successful.
 @li `CMPI_RC_ERR_FAILED` - Other error occurred.
 @li `CMPI_RC_ERR_NOT_FOUND` - MI name not found.
 @li `CMPI_RC_ERR_NOT_SUPPORTED` - MI type not supported for this MI name.
 @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.

 CMPI 2.1 documented these return codes for the first time. For backwards
 compatibility, MBs conforming to CMPI 2.1 that use MIs conforming to prior
 CMPI releases shall tolerate other uses of these return codes as well as
 additional return codes.
*/

/**
 * @}
 * @addtogroup mb-tables
 * @{
 */

/**
 * @brief CMPIBroker structure.
 *
 * The CMPIBroker structure is the anchor object of the MB (Management Broker,
 * also known as CIMOM). A pointer to this structure is passed to the MI in its
 * factory function (see @ref mi-factory "MI Factory Functions") and needs to
 * be passed to many MB services.
 */
typedef struct _CMPIBroker {

    /**
     * @brief Opaque pointer to MB-specific implementation data for the MB.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for some MB services (thread
     *     registration, indications services, and client services).
     */
    const CMPIBrokerFT* bft;

    /**
     * @brief Pointer to the function table for some MB services (factory and
     *     miscellaneous services).
     */
    const CMPIBrokerEncFT* eft;

    /**
     * @brief Pointer to the function table for MB operating system
     *     encapsulation services.
     */
    const CMPIBrokerExtFT* xft;

#ifdef CMPI_VER_200

    /**
     * @brief Pointer to the function table for MB memory enhancement services.
     *
     * If the
     * @ref CMPI_MB_Supports_MemEnhancements "Memory Enhancement Services"
     * capability is not available, this pointer is NULL.
     *
     * @added200 Added in CMPI 2.0.0.
     */
    const CMPIBrokerMemFT* mft;

#endif /*CMPI_VER_200*/

} CMPIBroker;

/**
 * @brief Function table for some MB services (thread registration, indications
 *     services, and client services).
 *
 * This function table is referenced by the CMPIBroker structure, and provides
 * @ref broker-thread-reg "Thread Registration Services",
 * @ref broker-indications "Indications Services", and
 * @ref broker-client "Client Services (\"up-calls\")".
 *
 * For functions that are not supported, their function pointers in this
 * function table shall not be NULL, but shall point to a function that can be
 * called and then indicate back to the caller that it is not supported, as
 * specified in the description of the function.
 */
typedef struct _CMPIBrokerFT {

    /**
     * @brief MB capabilities.
     *
     * For a definition of the test masks, see
     * @ref mb-capabilities "MB Capabilities".
     */
    unsigned int brokerCapabilities;

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     *
     * Note: This is not the version of the MB.
     * @see CBBrokerVersion()
     */
    CMPIVersion brokerVersion;

    /**
     * @brief Informal MB-specific name for this MB.
     *
     * @see CBBrokerName()
     * @todo (KS) what is the source that sets the brokerName value.
     *       I note in Pegasus that we do not use it for much of
     *       anything.
     */
    const char* brokerName;

    /**
     *   @addtogroup broker-thread-reg
     *   @{
     */

// DONE_AM Next function is already synced with spec.
    /**
     @brief Prepare the MB to accept a new thread that will be using MB
         functions.

     CMPIBrokerFT.prepareAttachThread() prepares the MB to accept a new thread
     that will be using MB functions. This function is expected to be called in
     the existing thread.

     @param mb Points to a CMPIBroker structure.
     @param ctx
     @parblock
         Points to the CMPIContext object that was used to invoke the MI
         function that calls this MB function.

         The opaque part of the CMPIContext object can be used by the MB to
         carry the MB internal security context. Such MBs can maintain the
         security context for the new thread in the returned copy of the
         CMPIContext object.
     @endparblock
     @return @parblock
         If successful, a pointer to a CMPIContext object to be used by the
         thread to be attached will be returned. This is used for subsequent
         CMPIBrokerFT.attachThread() and CMPIBrokerFT.detachThread()
         invocations.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     For historical reasons, no additional error information is passed back.

     @see CBPrepareAttachThread()
    */
    CMPIContext* (*prepareAttachThread) (const CMPIBroker* mb,
        const CMPIContext* ctx);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Inform the MB that the current thread will begin using MB functions.

     CMPIBrokerFT.attachThread() informs the MB that the current (newly created)
     thread with the specified context will begin using MB functions.

     @param mb Points to a CMPIBroker structure.
     @param ctx
     @parblock
         Points to the CMPIContext object that was returned by a prior call to
         CMPIBrokerFT.prepareAttachThread().

         The opaque part of the CMPIContext object can be used by the MB to
         carry the MB internal security context. Such MBs can set up the
         security context for the current thread in this function.
     @endparblock
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p mb handle or @p ctx handle is
         invalid.

     @see CBAttachThread()
    */
    CMPIStatus (*attachThread) (const CMPIBroker* mb, const CMPIContext* ctx);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Inform the MB that the current thread will no longer use MB
         functions.

     CMPIBrokerFT.detachThread() informs the MB that the current thread will no
     longer be using MB functions.

     @param mb Points to a CMPIBroker structure.
     @param ctx
     @parblock
         Points to the CMPIContext object that was returned by the prior call to
         CMPIBrokerFT.prepareAttachThread().

         The opaque part of the CMPIContext object can be used by the MB to
         carry the MB internal security context. Such MBs can set up the
         security context for the current thread in this function.
     @endparblock
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p mb handle or @p ctx handle is
         invalid.

     @see CBDetachThread()
    */
    CMPIStatus (*detachThread) (const CMPIBroker* mb, const CMPIContext* ctx);

    /**
     *   @}
     *   @addtogroup broker-indications
     *   @{
     */

// DONE_AM Next function is already synced with spec.
    /**
     @brief Request delivery of an indication.

     CMPIBrokerFT.deliverIndication() requests the delivery of an indication.

     The MB will locate pertinent subscribers and send the indication to each
     of them.

     This function may be called by an MI regardless of whether or not there
     are any active indication filters or indication filter collections
     that cover the indication to be delivered. If there are no such filters
     or filter collections, this will not cause the function to fail. For
     the concept of coverage of indications by an indication filter or
     indication filter collection, see @ref ref-dmtf-dsp1054 "DSP1054".

     This function may be called by an MI regardless of whether or not
     the MB is ready for processing the delivery of indications, as
     communicated to the MI via CMPIIndicationMIFT.enableIndications() and
     CMPIIndicationMIFT.disableIndications().  If the MB is not
     ready for processing the delivery of indications, this will not
     cause the function to fail. The MB implementation may choose to
     drop the indication in this case, or to queue the indication
     for later delivery.

     This function may be called by any MI function, and by any threads
     created by MIs that are registered with the MB (see
     @ref broker-thread-reg "Thread Registration Services").

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to the CMPIContext object that was used to invoke the MI
         function that calls this MB function, or that was used to register the
         thread that calls this MB function.
     @param ns Points to a string specifying the name of the *origin namespace*
         of the indication (see @ref ref-dmtf-dsp1054 "DSP1054" for a
         definition).
     @param ind Points to a CMPIInstance object containing the indication
         instance. An instance path specified in that CMPIInstance object is
         meaningless for indication instances and will be ignored by the MB.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.@n
         Note: If the MB is not ready for processing the delivery of
         indications, it may drop the indication and still return success.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The handle specified by @p ind
          is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The namespace specified by
         @p ns is invalid, or the indication instance specified by
         @p ind is invalid.
     @capindications This function is part of the Indications MB capability.

     @see CBDeliverIndication()
    */
    CMPIStatus (*deliverIndication) (const CMPIBroker* mb,
        const CMPIContext* ctx, const char* ns, const CMPIInstance* ind);

    /**
     *   @}
     *   @addtogroup broker-client
     *   @{
     */

// DONE_AM Next function is already synced with spec.
    /**
     @brief Enumerate the instance paths of the instances of a given class (and
         its subclasses).

     CMPIBrokerFT.enumerateInstanceNames() enumerates the instance paths of the
     instances of a given class (and its subclasses).

     The target MIs are identified by the MB based on @p classPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param classPath Points to a CMPIObjectPath object that references the
         given class and that shall contain the namespace and class name
         components. The hostname and key components, if present, will be
         ignored by the MB.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIObjectPath objects that represent the
         enumerated instance paths.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p classPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in @p classPath
          does not exist.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found. (**Deprecated**)
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capread This function is part of the Basic Read MB capability.

     @see CBEnumInstanceNames()
     @deprecated The `CMPI_RC_ERR_NOT_FOUND` return code of this function
         is deprecated since CMPI 2.1. If no instances exist, the MB should
         instead return success with an empty result set.
         The MI shall treat this return code as a successful return of an
         empty result set.
    */
    CMPIEnumeration* (*enumerateInstanceNames) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* classPath,
        CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Get an existing instance.

     CMPIBrokerFT.getInstance() gets an existing instance.

     The target MI is identified by the MB based on @p instPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         The MI may specify invocation flags (@ref CMPIInvocationFlags entry)
         as needed.
     @param instPath Points to a CMPIObjectPath object that references the
         instance to be retrieved and that shall contain the namespace, class
         name, and key components. The hostname component, if present, will be
         ignored by the MB.
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. The returned instance will not include
         elements for any properties missing from this list. If @p properties
         is NULL, this indicates that all properties will be included
         in the returned instance.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIInstance object containing the
         retrieved instance will be returned.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.
         Specifically, the MI shall not use CMPIBrokerMemFT.freeInstance() on
         the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified
         in @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The property list specified
         in @p properties is invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found.
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capread This function is part of the Basic Read MB capability.

     @see CBGetInstance()
    */
    CMPIInstance* (*getInstance) (const CMPIBroker* mb, const CMPIContext* ctx,
        const CMPIObjectPath* instPath, const char** properties,
        CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Create an instance of a given class.

     CMPIBrokerFT.createInstance() creates an instance of a given class.

     The target MI is identified by the MB based on @p classPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param classPath Points to a CMPIObjectPath object that references the
         class of the instance to be created and that shall contain the
         namespace and class name components. The hostname and key components,
         if present, will be ignored by the MB.
     @param newInst Points to a CMPIInstance object specifying property values
         for the new instance. The object path component within this
         CMPIInstance object has no meaning; it should not be provided by the
         calling MIs. The MB will pass the definition of the new instance on to
         the target MI, unchanged.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIObjectPath object containing the
         assigned instance path will be returned.

         The new object will be released automatically by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.
         Specifically, the MI shall not use CMPIBrokerMemFT.freeObjectPath()
         on the new object.

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p classPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p classPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The instance specified in
         @p inst is invalid.
     @li `CMPI_RC_ERR_ALREADY_EXISTS` - Instance already exists.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capmanipulation This function is part of the Instance Manipulation
         MB capability.

     @see CBCreateInstance()
     @deprecated The use of the key component within @p classPath
         is deprecated since CMPI 2.1; this key component should not be provided
         by the calling MIs. Initial key values can be supplied as properties
         in @p newInst.
    */
    CMPIObjectPath* (*createInstance) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* classPath,
        const CMPIInstance* newInst, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Modify property values of an existing instance.

     CMPIBrokerFT.modifyInstance() modifies property values of an existing
     instance.

     The target MI is identified by the MB based on @p instPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath Points to a CMPIObjectPath object that references
         the instance to be modified and that shall contain the namespace,
         class name, and key components. The hostname component, if present,
         will be ignored by the MB.
     @param modInst Points to a CMPIInstance object specifying new
         values for the properties to be modified. The object path
         component within this CMPIInstance object has no meaning; it
         should not be provided by the calling MIs and should not
         be used by the MB.
     @param propertyList If not NULL, defines the list of property names to
         be modified. If NULL, all properties will be modified. The end of
         the list is signaled by a NULL character pointer.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in @p instPath
         does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The instance specified in
         @p modInst, or the properties specified in @p propertyList are invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capmanipulation This function is part of the Instance Manipulation
         MB capability.

     @see CBModifyInstance()
    */
    CMPIStatus (*modifyInstance) (const CMPIBroker* mb, const CMPIContext* ctx,
        const CMPIObjectPath* instPath, const CMPIInstance* modInst,
        const char** properties);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Delete an existing instance.

     CMPIBrokerFT.deleteInstance() deletes an existing instance.

     The target MI is identified by the MB based on @p instPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath Points to a CMPIObjectPath object that references the
         instance to be deleted and that shall contain the namespace,
         class name, and key components. The hostname component, if present,
         will be ignored by the MB.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capmanipulation This function is part of the Instance Manipulation
         MB capability.

     @see CBDeleteInstance()
    */
    CMPIStatus (*deleteInstance) (const CMPIBroker* mb, const CMPIContext* ctx,
        const CMPIObjectPath* instPath);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Execute a query on a given class and return the query result.

     CMPIBrokerFT.execQuery() executes a query on a given class and returns the
     query result.

     The target MI is identified by the MB based on @p classPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param classPath Points to a CMPIObjectPath object that references
         the given class to be queried and that shall contain the namespace
         and class name components. The hostname and key components,
         if present, will be ignored by the MB.
     @param query Points to a string containing the select expression.
     @param lang Points to a string containing the query language.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIInstance objects that represent the query
         result.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p classPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p classPath does not exist.
     @li `CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED` - Query language not
         supported.
     @li `CMPI_RC_ERR_INVALID_QUERY` - Invalid query.
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capqueryexec This function is part of the Query Execution MB capability.

     @see CBExecQuery()
    */
    CMPIEnumeration* (*execQuery) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* classPath,
        const char* query, const char* lang, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Enumerate the instances of a given class (and its subclasses).

     CMPIBrokerFT.enumerateInstances() enumerates the instances of a given
     class (and its subclasses). The set of properties in the result instances
     can be controlled via @p properties and via the CMPI_FLAG_LocalOnly and
     CMPI_FLAG_DeepInheritance flags in the @ref CMPIInvocationFlags entry of
     @p ctx.

     The target MIs are identified by the MB based on @p classPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         The MI may specify invocation flags (@ref CMPIInvocationFlags entry)
         as needed.
     @param classPath Points to a CMPIObjectPath object that references
         the given class and that shall contain the namespace and class
         name components. The hostname and key components, if present,
         will be ignored by the MB.
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. Each returned instance will not include
         elements for any properties missing from this list. If the properties
         argument is NULL, this indicates that all properties will be included
         in each returned instance.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIInstance objects that represent the
         enumerated instances.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p classPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p classPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The property list specified in
         @p properties is invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found. (**Deprecated**)
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capread This function is part of the Basic Read MB capability.

     @see CBEnumInstances()
     @deprecated The `CMPI_RC_ERR_NOT_FOUND` return code of this function
         is deprecated since CMPI 2.1. If no instances exist, the MB should
         instead return success with an empty result set.
         The MI shall treat this return code as a successful return of an
         empty result set.
    */
    CMPIEnumeration* (*enumerateInstances) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* classPath,
        const char** properties, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Enumerate the instances associated with a given source instance.

     CMPIBrokerFT.associators() enumerates the instances associated with a
     given source instance.

     The target MIs are identified by the MB based on @p instPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath Points to a CMPIObjectPath object that references
         the given source instance that shall contain the namespace,
         class name, and key components. The hostname component, if present,
         will be ignored by the MB.
     @param assocClass If not NULL, shall be a valid association class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object shall be associated to the source object via an
         instance of this class or one of its subclasses.
     @param resultClass If not NULL, shall be a valid class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object shall be either an instance of this class or one
         of its subclasses.
     @param role If not NULL, shall be a valid property name.
         It acts as a filter on the returned set of objects by mandating
         that each returned object shall be associated to the source object
         via an association in which the source object plays the specified role
         (i.e. the name of the property in the association class that refers
         to the source object shall match the value of this parameter).
     @param resultRole If not NULL, shall be a valid property name.
         It acts as a filter on the returned set of objects by mandating
         that each returned object shall be associated to the source object
         via an association in which the returned object plays the specified
         role (i.e. the name of the property in the association class that
         refers to the returned object shall match the value of this parameter).
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. Each returned instance will not include
         elements for any properties missing from this list. If @p properties
         is NULL, this indicates that all properties will be included in each
         returned instance.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIInstance objects that represent the
         enumerated instances.

         The new object will be released automatically by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p assocClass,
         @p resultClass, @p role, @p resultRole, or
         @p properties arguments are invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found. (**Deprecated**)
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capassociations This function is part of the Association Traversal
         MB capability.

     @see CBAssociators()
     @deprecated The `CMPI_RC_ERR_NOT_FOUND` return code of this function
         is deprecated since CMPI 2.1. If no instances exist, the MB should
         instead return success with an empty result set.
         The MI shall treat this return code as a successful return of an
         empty result set.
    */
    CMPIEnumeration* (*associators) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* instPath,
        const char* assocClass, const char* resultClass, const char* role,
        const char* resultRole, const char** properties, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Enumerate the instance paths of the instances associated with a
         given source instance.

     CMPIBrokerFT.associatorNames() enumerates the instance paths of the
     instances associated with a given source instance.

     The target MIs are identified by the MB based on @p instPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath Points to a CMPIObjectPath object that references
         the given source instance that shall contain the namespace,
         class name, and key components. The hostname component, if present,
         will be ignored by the MB.
     @param assocClass If not NULL, shall be a valid association class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object shall be associated to the source object via an
         instance of this class or one of its subclasses.
     @param resultClass If not NULL, shall be a valid class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object shall be either an instance of this class or one
         of its subclasses.
     @param role If not NULL, shall be a valid property name.
         It acts as a filter on the returned set of objects by mandating
         that each returned object shall be associated to the source object
         via an association in which the source object plays the specified role
         (i.e. the name of the property in the association class that refers
         to the source object shall match the value of this parameter).
     @param resultRole If not NULL, shall be a valid property name.
         It acts as a filter on the returned set of objects by mandating
         that each returned object shall be associated to the source object
         via an association in which the returned object plays the specified
         role (i.e. the name of the property in the association class that
         refers to the returned object shall match the value of this parameter).
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIObjectPath objects that represent the
         enumerated instance paths.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p assocClass, @p resultClass,
         @p role, or @p resultRole arguments are invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found. (**Deprecated**)
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capassociations This function is part of the Association Traversal
         MB capability.

     @see CBAssociatorNames()
     @deprecated The `CMPI_RC_ERR_NOT_FOUND` return code of this function
         is deprecated since CMPI 2.1. If no instances exist, the MB should
         instead return success with an empty result set.
         The MI shall treat this return code as a successful return of an
         empty result set.
    */
    CMPIEnumeration* (*associatorNames) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* instPath,
        const char* assocClass, const char* resultClass, const char* role,
        const char* resultRole, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Enumerate the association instances referencing a given source
         instance.

     CMPIBrokerFT.references() enumerates the association instances referencing
     a given source instance.

     The target MIs are identified by the MB based on @p instPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath Points to a CMPIObjectPath object that references
         the given source instance that shall contain the namespace,
         class name, and key components. The hostname component, if present,
         will be ignored by the MB.
     @param resultClass If not NULL, shall be a valid class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object shall be either an instance of this class or one
         of its subclasses.
     @param role If not NULL, shall be a valid property name.
         It acts as a filter on the returned set of objects by mandating
         that each returned object shall be associated to the source object
         via an association in which the source object plays the specified role
         (i.e. the name of the property in the association class that refers
         to the source object shall match the value of this parameter).
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. Each returned instance will not include
         elements for any properties missing from this list. If @p properties
         is NULL, this indicates that all properties will be included in each
         returned instance.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIInstance objects that represent the
         enumerated instances.

         The new object will be released automatically by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The
         @p resultClass, or @p role arguments are invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found. (**Deprecated**)
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capassociations This function is part of the Association Traversal
         MB capability.

     @see CBReferences()
     @deprecated The `CMPI_RC_ERR_NOT_FOUND` return code of this function
         is deprecated since CMPI 2.1. If no instances exist, the MB should
         instead return success with an empty result set.
         The MI shall treat this return code as a successful return of an
         empty result set.
    */
    CMPIEnumeration* (*references) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* instPath,
        const char* resultClass, const char* role, const char** properties,
        CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Enumerate the instance paths of the association instances
         referencing a given source instance.

     CMPIBrokerFT.referenceNames() enumerates the instance paths of the
     association instances referencing a given source instance.

     The target MIs are identified by the MB based on @p instPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath Points to a CMPIObjectPath object that references
         the given source instance that shall contain the namespace,
         class name, and key components. The hostname component, if present,
         will be ignored by the MB.
     @param resultClass If not NULL, shall be a valid class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object shall be either an instance of this class or one
         of its subclasses.
     @param role If not NULL, shall be a valid property name.
         It acts as a filter on the returned set of objects by mandating
         that each returned object shall be associated to the source object
         via an association in which the source object plays the specified role
         (i.e. the name of the property in the association class that refers
         to the source object shall match the value of this parameter).
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIObjectPath objects that represent the
         enumerated instance paths.

         The new object will be released automatically by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p resultClass, or @p role
         arguments are invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found. (**Deprecated**)
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capassociations This function is part of the Association Traversal
         MB capability.

     @see CBReferenceNames()
     @deprecated The `CMPI_RC_ERR_NOT_FOUND` return code of this function
         is deprecated since CMPI 2.1. If no instances exist, the MB should
         instead return success with an empty result set.
         The MI shall treat this return code as a successful return of an
         empty result set.
    */
    CMPIEnumeration* (*referenceNames) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* instPath,
        const char* resultClass, const char* role, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Invoke a method on a target object.

     CMPIBrokerFT.invokeMethod() invokes a named, extrinsic method on a target
     object. Instance methods (i.e., non-static methods) can be invoked only
     on instances. Class methods (i.e., static methods) can be invoked on
     instances and classes.

     The target MI is identified by the MB based on @p objPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param objPath
     @parblock
         Points to the CMPIObjectPath object that references the target object
         on which the method is invoked.

         If the target object is an instance, this object path shall contain
         the namespace, class name, and key components. The hostname component,
         if present, will be ignored by the MB.

         If the target object is a class, this object path shall contain the
         namespace and class name components. The hostname and key components,
         if present, will be ignored by the MB.
     @endparblock
     @param method Points to a string containing the method name.
     @param in Points to a CMPIArgs object containing the method input
         parameters.
     @param [out] out
     @parblock
         Points to an empty CMPIArgs object that, upon successful return of the
         method, will have been updated to contain the method output parameters.

         The objects returned in the CMPIArgs object shall not be explicitly
         released by the MI; they will be automatically released by the MB, as
         described in
         Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
     @endparblock
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPIData structure containing the method return
         value will be returned.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Invocation of extrinsic methods is not
         supported by the MB (that is, the
         @ref CMPI_MB_InstanceManipulation "Instance Manipulation" capability
         is not available).
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p objPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p objPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The method parameters specified in
         the @p in or @p out arguments are invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - Instance not found.
     @li `CMPI_RC_ERR_METHOD_NOT_AVAILABLE` - The extrinsic method is not
         supported by the targeted MI.
     @li `CMPI_RC_ERR_METHOD_NOT_FOUND` - Method not defined in the class.
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capmanipulation This function is part of the Instance Manipulation
         MB capability.

     @see CBInvokeMethod()
    */
    CMPIData (*invokeMethod) (const CMPIBroker* mb, const CMPIContext* ctx,
        const CMPIObjectPath* objPath, const char* method,
        const CMPIArgs* in, CMPIArgs* out, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Set or modify a property of an existing instance. (**Deprecated**)

     CMPIBrokerFT.setProperty() sets or modifies a property of an existing
     instance.

     The target MI is identified by the MB based on @p instPath.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.

     @param instPath Points to a CMPIObjectPath object that references the
         instance to be modified and that shall contain the namespace, class
         name, and key components. The hostname component, if present, will
         be ignored by the MB.
     @param name Points to a string specifying the property name.
     @param value Points to a CMPIValue structure containing the non-NULL value
         to be assigned to the property, or is NULL to specify that NULL is to
         be assigned.
     @param type
     @parblock
         A CMPIType value defining the type of the value to be assigned to the
         property.
         
         If the value of @p type is @ref CMPI_chars or @ref CMPI_charsA, the
         C-language string to which @p value.chars points is copied by this
         function and the original string memory may be freed by the MI right
         after this function returns.
     @endparblock
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath is invalid.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in @p instPath
         does not exist.
     @li `CMPI_RC_ERR_NOT_FOUND` - The class specified in @p instPath
         is not found.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Property not found.
     @li `CMPI_RC_ERR_TYPE_MISMATCH` - Value types incompatible.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capwrite This function is part of the Basic Write MB capability.
     @deprecated This function is deprecated since CMPI 2.1, in accord with the
         deprecation of property client operations in DMTF specifications.
         MBs shall implement this function by invoking
         CMPIInstanceMIFT.modifyInstance() if CMPIPropertyMIFT.setProperty()
         is not implemented by the target MI.
         New MIs should replace the use of CMPIBrokerFT.setProperty() with the
         use of CMPIBrokerFT.modifyInstance().
    */
    CMPIStatus (*setProperty) (const CMPIBroker* mb, const CMPIContext* ctx,
        const CMPIObjectPath* instPath, const char* name,
        const CMPIValue* value, CMPIType type);

// TODO_AM Sync function descriptions with spec, from here on down.
    /**
     @brief Get the named property of a given instance. (**Deprecated**)

     CMPIBrokerFT.getProperty() gets the named property value of an
     Instance defined by the @p instPath parameter.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath ObjectPath containing namespace, classname
         and key components.
     @param name Property name
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns CMPIData with property
         value.

         If not successful CMPIData.state will have CMPI_BadValue flag
         set to true
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not
         supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace
         specified in @p instPath is invalid.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_NOT_FOUND` - The class specified in
         @p instPath is not found.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Property not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capread This function is part of the Basic Read MB capability.

     @see CMGetProperty()
     @deprecated This function is deprecated since CMPI 2.1, in accord with the
         deprecation of property client operations in DMTF specifications.
         MBs shall implement this function by invoking
         CMPIInstanceMIFT.getInstance() if CMPIPropertyMIFT.getProperty()
         is not implemented by the target MI.
         New MIs should replace the use of CMPIBrokerFT.getProperty() with the
         use of CMPIBrokerFT.getInstance().
    */
    CMPIData (*getProperty) (const CMPIBroker* mb, const CMPIContext* ctx,
        const CMPIObjectPath* instPath, const char* name, CMPIStatus* rc);

    /**
     @brief Enumerate the instances of a given class (and its subclasses),
         returning only those that match the given query filter.

     CMPIBrokerFT.enumerateInstancesFiltered() enumerates the instances of a
     given class and its subclasses, returning only instances that match
     @p filterQuery. If no such instances are found, the function will return
     success with an empty enumeration.

     The target MIs are identified by the MB based on @p classPath.

     The set of properties in the result instances can be controlled via
     @p properties and via the @ref CMPI_FLAG_LocalOnly and
     @ref CMPI_FLAG_DeepInheritance flags in the @ref CMPIInvocationFlags entry
     of @p ctx.
   
     Because the response interface does not support extended error responses,
     there is no argument to request continue on error as part of this function.
     The MB is expected to invoke any target MIs with @p continueOnError set to
     false.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         The MI may specify invocation flags (@ref CMPIInvocationFlags entry)
         as needed.
     @param classPath Points to a CMPIObjectPath object that references the
         given class and that shall contain the namespace and class name
         components. The hostname and key components, if present, will be
         ignored by the MB.
     @param properties If not NULL, an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. Each returned instance will not include
         elements for any properties missing from this list. If this argument
         is NULL, this indicates that all properties will be included in each
         returned instance.
     @param filterQueryLanguage Defines the query language used by
         @p filterQuery. If @p filterQueryLanguage is NULL, @p filterQuery is
         ignored and no filtering is performed.
     @param filterQuery Defines the query in the query language defined by
         @p filterQueryLanguage. If NULL, no filtering is performed.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIInstance objects that represent the
         enumerated instances.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified
         in @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p instPath does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The property list specified
         in @p properties is invalid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.
     @li `CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED` - The MB does not support
         the query language defined in the input arguments.
     @li `CMPI_RC_ERR_INVALID_QUERY` - @p filterQuery is not a valid filter in
         the language defined by @p filterQueryLanguage.
     @li `CMPI_RC_ERR_QUERY_FEATURE_NOT_SUPPORTED` - A feature of the query
         language is not supported.
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capread This function is part of the Basic Read MB capability.

     @see CBEnumInstancesFiltered()
     @added210 Added in CMPI 2.1.0.
    */
    CMPIEnumeration* (*enumerateInstancesFiltered) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* classPath,
        const char** properties, const char* filterQueryLanguage,
        const char* filterQuery, CMPIStatus* rc);

    /**
     @brief Enumerate the instances associated with a given source instance,
         returning only those that match the given filters.

     CMPIBrokerFT.associatorsFiltered() enumerates the instances associated with
     a given source instance, applying any filters defined in the arguments to
     return only instances that match the filters. If no such instances are
     found, the function will return success with an empty enumeration.

     The target MIs are identified by the MB based on @p instPath.

     Because the response interface does not support extended error responses,
     there is no argument to request continue on error as part of this function.
     The MB is expected to invoke any target MIs with @p continueOnError set to
     false.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath Points to a CMPIObjectPath object that references the
         given source instance and that shall contain the namespace, class name,
         and key components. The hostname component, if present, will be
         ignored by the MB.
     @param assocClass If not NULL, shall be a valid association class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object must be associated with the source object via an
         instance of this class or one of its subclasses.
     @param resultClass If not NULL, shall be a valid class name. It acts as a
         filter on the returned set of objects by mandating that each returned
         object shall be an instance of this class or one of its subclasses.
     @param role If not NULL, shall be a valid property name. It acts as a
         filter on the returned set of objects by mandating that each returned
         object must be associated with the source object via an association in
         which the source object plays the specified role (i.e., the name of
         the property in the association class that refers to the source object
         shall match the value of this argument).
     @param resultRole If not NULL, shall be a valid property name. It acts as
         a filter on the returned set of objects by mandating that each
         returned object must be associated with the source object via an
         association in which the returned object plays the specified role
         (i.e., the name of the property in the association class that refers
         to the returned object shall match the value of this argument).
     @param properties If not NULL, an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. Each returned instance will not include
         elements for any properties missing from this list. If this argument
         is NULL, this indicates that all properties will be included in each
         returned instance.
     @param filterQueryLanguage Defines the query language used by
         @p filterQuery. If @p filterQueryLanguage is NULL, @p filterQuery is
         ignored and no filtering is performed.
     @param filterQuery Defines the query in the query language defined by
         @p filterQueryLanguage. If NULL, no filtering is performed.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIInstance objects that represent the
         enumerated instances.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath is invalid or does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in @p instPath is
         invalid or does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p assocClass, @p resultClass,
         @p role, @p resultRole, or @p properties arguments are invalid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.
     @li `CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED` - The MB does not support
         the query language defined in the input arguments.
     @li `CMPI_RC_ERR_INVALID_QUERY` - @p filterQuery is not a valid filter in
         the language defined by @p filterQueryLanguage.
     @li `CMPI_RC_ERR_QUERY_FEATURE_NOT_SUPPORTED` - A feature of the query
         language is not supported.
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capassociations This function is part of the Association Traversal
         MB capability.

     @see CBAssociatorsFiltered()
     @added210 Added in CMPI 2.1.0.
    */
    CMPIEnumeration* (*associatorsFiltered) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* instPath,
        const char* assocClass, const char* resultClass,
        const char* role, const char* resultRole,
        const char** properties, const char* filterQueryLanguage,
        const char* filterQuery, CMPIStatus* rc);

    /**
     @brief Enumerate the instances referencing a given source instance,
         returning only those that match the given filters.

     CMPIBrokerFT.referencesFiltered() enumerates the instances referencing
     a given source instance, applying any filters defined in the arguments to
     return only instances that match the filters. If no such instances are
     found, the function will return success with an empty enumeration.

     The target MIs are identified by the MB based on @p instPath.

     Because the response interface does not support extended error responses,
     there is no argument to request continue on error as part of this function.
     The MB is expected to invoke any target MIs with @p continueOnError set to
     false.

     @param mb Points to a CMPIBroker structure.
     @param ctx Points to a CMPIContext object that specifies the same
         principal (@ref CMPIPrincipal entry), role (@ref CMPIRole entry),
         accept language (@ref CMPIAcceptLanguage entry), and content language
         (@ref CMPIContentLanguage entry) as the CMPIContext object that was
         used to invoke the MI function that calls this MB function.
         Any invocation flags (@ref CMPIInvocationFlags entry) will be ignored
         by this function.
     @param instPath Points to a CMPIObjectPath object that references the
         given source instance and that shall contain the namespace, class name,
         and key components. The hostname component, if present, will be
         ignored by the MB.
     @param resultClass If not NULL, shall be a valid class name. It acts as a
         filter on the returned set of objects by mandating that each returned
         object shall be an instance of this class or one of its subclasses.
     @param role If not NULL, shall be a valid property name. It acts as a
         filter on the returned set of objects by mandating that each returned
         object must be associated with the source object via an association in
         which the source object plays the specified role (i.e., the name of
         the property in the association class that refers to the source object
         shall match the value of this argument).
     @param properties If not NULL, an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. Each returned instance will not include
         elements for any properties missing from this list. If this argument
         is NULL, this indicates that all properties will be included in each
         returned instance.
     @param filterQueryLanguage Defines the query language used by
         @p filterQuery. If @p filterQueryLanguage is NULL, @p filterQuery is
         ignored and no filtering is performed.
     @param filterQuery Defines the query in the query language defined by
         @p filterQueryLanguage. If NULL, no filtering is performed.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumeration object will be
         returned, containing CMPIInstance objects that represent the
         enumerated instances.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace specified in
         @p instPath is invalid or does not exist.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in @p instPath is
         invalid or does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p resultClass, @p role, or
         @p properties arguments are invalid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.
     @li `CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED` - The MB does not support
         the query language defined in the input arguments.
     @li `CMPI_RC_ERR_INVALID_QUERY` - @p filterQuery is not a valid filter in
         the language defined by @p filterQueryLanguage.
     @li `CMPI_RC_ERR_QUERY_FEATURE_NOT_SUPPORTED` - A feature of the query
         language is not supported.
     @li `CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED` - Limits exceeded.

     Extended error handling is not supported by this MB function; thus, any
     CMPIError objects returned by the targeted MI cannot be made available to
     the calling MI.
     @capassociations This function is part of the Association Traversal
         MB capability.

     @see CBAssociatorsFiltered()
     @added210 Added in CMPI 2.1.0.
    */
    CMPIEnumeration* (*referencesFiltered) (const CMPIBroker* mb,
        const CMPIContext* ctx, const CMPIObjectPath* instPath,
        const char* resultClass, const char* role,
        const char** properties, const char* filterQueryLanguage,
        const char* filterQuery, CMPIStatus* rc);

    /**
     *   @}
     */

} CMPIBrokerFT;

/**
 * @brief Function table for some MB services (factory and miscellaneous
 *     services).
 *
 * This function table is referenced by the CMPIBroker structure, and provides
 * @ref brokerenc-factory "Factory Services" and
 * @ref brokerenc-misc "Miscellaneous Services".
 *
 * For functions that are not supported, their function pointers in this
 * function table shall not be NULL, but shall point to a function that can be
 * called and then indicate back to the caller that it is not supported, as
 * specified in the description of the function.
 */
typedef struct _CMPIBrokerEncFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     *   @addtogroup brokerenc-factory
     *   @{
     */

    /**
     @brief Create a new CMPIInstance object initialized to a given instance
         path.

     CMPIBrokerEncFT.newInstance() creates a new
     CMPIInstance object. The new object should have no properties.
     The purpose of class-defined derault values for properties is
     to act as defaults for unspecified input properties when a
     client creates an instance, not to act as defualts for not
     explicity set properties when a client retrieves an instance.

     @param mb Points to a CMPIBroker structure.
     @param instPath ObjectPath containing namespace and classname.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful returns the newly created
         instance. if not successful returns NULL.

         The new object will be automatically released by the MB.
         If the new object is no longer used by the MI, it
         may be explicitly released by the MI using
         CMPIBrokerMemFT.freeInstance().
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace
         specified in @p instPath is invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - The class specified in
         @p instPath is not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMNewInstance()
    */
    CMPIInstance* (*newInstance) (const CMPIBroker* mb,
        const CMPIObjectPath* instPath, CMPIStatus* rc);

    /**
     @brief Create a new CMPIObjectPath initialized to a given namespace and
         class name

     CMPIBrokerEncFT.newObjectPath() creates a new
     CMPIObjectPath object that is initialized to a given namespace
     and class name.

     @param mb Points to a CMPIBroker structure.
     @param ns Points to a string specifying the namespace name.
     @param cn Points to a string specifying the class name.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful returns the newly created
         CMPIObjectPath.

         If not successful returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace
         specified in @p ns does not exist.
     @li `CMPI_RC_ERR_NOT_FOUND` - Class in @p cn not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMNewObjectPath()
    */
    CMPIObjectPath* (*newObjectPath) (const CMPIBroker* mb, const char* ns,
        const char* cn, CMPIStatus* rc);

    /**
     @brief Create a new CMPIArgs object initialized to have no method
         parameters.

     CMPIBrokerEncFT.newArgs() creates a new CMPIArgs object with no method
     parameters.

     @param mb Points to a CMPIBroker structure.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns the newly created
         CMPIArgs object.

         If not successful returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMNewArgs()
    */
    CMPIArgs* (*newArgs) (const CMPIBroker* mb, CMPIStatus* rc);

    /**
     @brief Create a new CMPIString object initialized from a C-language string.

     CMPIBrokerEncFT.newString() creates a new
     CMPIString object that is initialized from a C-language
     string.

     @param mb Points to a CMPIBroker structure.
     @param data String data
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful returns the newly created CMPIString.

         If not successful returns NULL.

         The new object will be automatically released by the MB. If the new
         object is no longer used by the MI, it may be explicitly released
         by the MI using CMPIBrokerMemFT.freeString().
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMNewString()
    */
    CMPIString* (*newString) (const CMPIBroker* mb, const char* data,
        CMPIStatus* rc);

    /**
     @brief Create a new CMPIArray object of a given fixed array size for a
         given type of elements.

     CMPIBrokerEncFT.newArray() returns a new CMPIArray
     object. Once created, the size of the array is fixed by the @p size
     argument and all elements are of the same type defined by @p type.
     The array in initialized to have no array elements.

     @param mb Points to a CMPIBroker structure.
     @param size Specifies the size of the created CMPIArray
         (number of elements).
     @param type Specifies the type of each element. @p type
         specifies the type of single array elements; for
         example, the value for an array that contains CMPIString
         objects will be @ref CMPI_string, and not @ref CMPI_stringA.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful,returns a pointer to the new
         CMPIArray object.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         If the new object is no longer used by the MI, it may be explicitly
         released by the MI using CMPIBrokerMemFT.freeArray().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_DATA_TYPE` - Data type not valid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMNewArray()
    */
    CMPIArray* (*newArray) (const CMPIBroker* mb, CMPICount size,
        CMPIType type, CMPIStatus* rc);

    /**
     @brief Create a new CMPIDataTime object with current date and time.

     CMPIBrokerEncFT.newDateTime() creates a new
     CMPIDateTime object that is initialized with the current
     date and time.

     @param mb Points to a CMPIBroker structure.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the new
         CMPIDateTime object.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         If the new object is no longer used by the MI, it may be explicitly
         released by the MI using CMPIBrokerMemFT.freeDateTime().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMNewDateTime()
    */
    CMPIDateTime* (*newDateTime) (const CMPIBroker* mb, CMPIStatus* rc);

    /**
     @brief Create a new CMPIDateTime object initialized to a specific value.

     CMPIBrokerEncFT.newDateTimeFromBinary() creates
     a new CMPIDateTime object that is initialized with the
     specified date and time from @p binTime.

     @param mb Points to a CMPIBroker structure.
     @param binTime When interval is false, @p binTime
         contains a point in time value expressed as a 64-bit unsigned integer
         in microseconds since 00:00:00 GMT, January 1, 1970. Otherwise,
         @p binTime contains a time interval expressed as
         a 64-bit unsigned integer in microseconds
     @param interval When true, defines @p binTime definition to be
         an interval value.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the new
         CMPIDateTime object.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         If the new object is no longer used by the MI, it may be explicitly
         released by the MI using CMPIBrokerMemFT.freeDateTime().

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMNewDateTimeFromBinary()
    */
    CMPIDateTime* (*newDateTimeFromBinary) (const CMPIBroker* mb,
        CMPIUint64 binTime, CMPIBoolean interval, CMPIStatus* rc);

    /**
     @brief Create a new CMPIDateTime object initialized from input.

     CMPIBrokerEncFT.newDateTimeFromChars() creates a new
     CMPIDateTime object that is initialized with
     @p utcTime, the specified date and time.

     @param mb Points to a CMPIBroker structure.
     @param datetime Date/Time definition in CIM datetime string format.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful,returns a pointer to the new
         CMPIArray object.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         If the new object is no longer used by the MI, it may be explicitly
         released by the MI using CMPIBrokerMemFT.freeDateTime().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The utcTime format is invalid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMNewDateTimeFromChars()
    */
    CMPIDateTime* (*newDateTimeFromChars) (const CMPIBroker* mb,
        const char* datetime, CMPIStatus* rc);

    /**
     @brief Create a new CMPISelectExp object initialized from a select
         expression.

     CMPIBrokerEncFT.newSelectExp() creates a new CMPISelectExp
     object that is initialized from a select expression specified
     in a query language.

     @param mb Points to a CMPIBroker structure.
     @param query Points to a string containing the select expression.
     @param lang Points to a string containing the query language.
     @param [out] projection Points to a CMPIArray pointer that upon
         success will have been updated to point to a new CMPIArray
         object of CMPIString entries containing the
         projection specification. The pointer will be set to NULL if no
         projection was specified in the select expression. The
         projection specification is query language-specific. Hence
         the entries format of the projection output array
         CMPIString might be different depending on the query
         language. Be sure to check @p lang for the query
         language your MI will support.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful returns a pointer to the new
         CMPIArray object.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         If the new object is no longer used by the MI, it may be explicitly
         released by the MI using CMPIBrokerMemFT.freeDateTime().

         If not successful NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @li `CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED` - The query
         language is not supported.
     @li `CMPI_RC_ERR_INVALID_QUERY` - The query expression is not
         valid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p mb handle is invalid.
     @capquerynorm This function is part of the Query Normalization MB capability.

     @see CMNewSelectExp()
    */
    CMPISelectExp* (*newSelectExp) (const CMPIBroker* mb, const char* query,
        const char* lang, CMPIArray** projection, CMPIStatus* st);

    /**
     *   @}
     *   @addtogroup brokerenc-misc
     *   @{
     */

    /**
     @brief Test whether a class path is of a specified class or any of its
        subclasses.

     CMPIBrokerEncFT.classPathIsA() tests whether a class path is of a
     specified class or any of that class’s subclasses.

     @param mb Points to a CMPIBroker structure.
     @param classPath Points to the CMPIObjectPath object representing
         the class path that is being tested. It shall contain the namespace
         and class name components. Any key components in that CMPIObjectPath
         object will be ignored.
     @param className Specifies the class name to be tested for.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return If successful, a CMPIBoolean value indicating the test result will
         be returned, as follows:
         @li True indicates that the class path is of the specified class or
             any of that class's subclasses
         @li False indicates that this is not the case

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace implied by
         @p classPath is invalid.
     @li `CMPI_RC_ERR_NOT_FOUND` - The class implied by @p classPath is not
         found.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p className format is invalid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Either the @p mb or @p classPath handle
         is invalid.

     @see CMClassPathIsA()
    */
    CMPIBoolean (*classPathIsA) (const CMPIBroker* mb,
        const CMPIObjectPath* classPath, const char* className,
        CMPIStatus* rc);

    /**
     @brief Convert CMPIEncapsulated data type object into a string
         representation.

     CMPIBrokerEncFT.toString() converts any CMPI encapsulated
     data type object into an MB implementation-specific string
     representation. Intended for debugging purposes only.

     @param mb Points to a CMPIBroker structure.
     @param object Points to a CMPI encapsulated data type object.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful returns CMPIString from representation
         of @p object.

      If not successful returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Either the @p mb or
         @p object handle is invalid.

     @see CDToString()
    */
    CMPIString* (*toString) (const CMPIBroker* mb, const void* object,
        CMPIStatus* rc);

    /**
     @brief Tests whether a CMPI encapsulated data type object is of a
         specified CMPI type.

     CMPIBrokerEncFT.isOfType() verifies whether @p object is of
     CMPI type @p type. Intended for debugging purposes only.

     @param mb Points to a CMPIBroker structure.
     @param object A valid CMPI object.
     @param type Points to a string specifying a valid CMPI Object type
         ("CMPIInstance", "CMPIObjectPath", etc).
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status..
     @return If successful, a CMPIBoolean value indicating the test result will
         be returned, as follows:
         @li True indicates that @p type matches the @p object type;
         @li False indicates that this is not the case.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p type format is invalid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Either the @p mb or
         @p object handle is invalid.

     @see CDIsOfType()
    */
    CMPIBoolean (*isOfType) (const CMPIBroker* mb, const void* object,
        const char* type, CMPIStatus* rc);

    /**
     @brief Get the type name of a CMPI ensapsulated data type object.

     CMPIBrokerEncFT.getType() retrieves the CMPI type of @p object.

     Intended for debugging purposes only.

     @param mb Points to a CMPIBroker structure.
     @param [out] object If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a CMPIString
         object specifying the type name of the encapsulated data
         type (e.g., CMPIInstance) will be returned.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPI
         encapsulated data type object which will be released along with
         that object, or a new object created by the MB which will be
         automatically released by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Either the @p mb or
         @p object handle is invalid.

     @see CDGetType()
    */
    CMPIString* (*getType) (const CMPIBroker* mb, const void* object,
        CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief get a translated MB implementation-specific message text by message
         ID. (**Deprecated**)

     CMPIBrokerEncFT.getMessage() gets a translated MB implementation-specific
     message text by message ID. The language of the message text depends on
     the MB language setting.

     @param mb Points to a CMPIBroker structure.
     @param msgId Points to a string specifying a message ID that is used by the
         MB to locate a message template. The message ID values and
         corresponding message templates are MB implementation-specific.
     @param defMsg Points to a string specifying the default message template
         that will be used when message translation is not supported by the MB
         or @p msgId cannot be located. The message template string specified
         in @p defMsg may contain up to ten message insert triggers ($0 through
         $9). Each insert trigger string will be replaced with a string
         representation of the value of the corresponding insert pair in the
         variable arguments of this function. The MI is not affected when
         message translation is not supported by the MB, or the message cannot
         be found, because this function still succeeds and returns a message
         with expanded message insert triggers.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @param count The number of message insert pairs in the range 0 to 10.
     @param ... The variable arguments of this function are @p count pairs of
         arguments representing the message insert pairs as follows:
         `type, value`
         whereby @p type is a @ref CMPIType value and @p value is a value of
         that type.
         The following types are supported: @ref CMPI_sint32,
         @ref CMPI_uint32, @ref CMPI_sint64, @ref CMPI_uint64, @ref CMPI_real64,
         @ref CMPI_boolean, @ref CMPI_chars, and @ref CMPI_string.
     @return @parblock
         If successful, a pointer to a new CMPIString object containing either
         the translated or default message will be returned.

         If not successful, the default message without insert resolution will
         be returned.

         In both cases, the new object will be automatically released by the MB,
         as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.
         Specifically, the MI shall not use CMPIBrokerMemFT.freeString() on the
         new object.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_TYPE_MISMATCH` - Invalid insert pair.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - @p count value range violation.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p mb handle is invalid.
     @captranslation This function is part of the Message Translation
         MB capability.

     @todo KS: Add see macro
     @deprecated This function is deprecated since CMPI 2.1. Use
         CMPIBrokerEncFT.getMessage2() instead.
    */
    CMPIString* (*getMessage) (const CMPIBroker* mb, const char* msgId,
        const char* defMsg, CMPIStatus* rc, CMPICount count, ...);

    /**
     @brief Log a diagnostic message.

     CMPIBrokerEncFT.logMessage() logs a diagnostic message defined by the
     input arguments. It exists to provide a mechanism to MIs to
     provider information about errors, status, etc.

     This function shall be supported by the MB if the
     @ref CMPI_MB_Logging "Logging" capability
     is available; otherwise, it shall not be supported.

     @param mb Points to a CMPIBroker structure.
     @param severity @p level describes the level of
         logmessage. Levels are defined in Subclause 4.9(TBD).
     @param id If not NULL, points to a string specifying a message ID or
         any other identifying string.
     @param text If not NULL, points to a string specifying the
         message text to be logged.
     @param string If not NULL, points to a CMPIString object specifying the
         message text to be logged. @p string will be ignored
         when text is not NULL.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - @p mb or @p string
         handle is invalid.
     @caplogging This function is part of the Logging MB capability.

     @see CMLogMessage()
    */
    CMPIStatus (*logMessage) (const CMPIBroker* mb, int severity,
        const char* id, const char* text, const CMPIString* string);

    /**
     @brief Trace a diagnostic message with a specific trace level and
         component definition.

     CMPIBrokerEncFT.trace() traces a diagnostic message with a
     specific trace level. This function exists to provide a mechanism to MIs
     by which debugging information may be generated.

     This function shall be supported by the MB if the
     @ref CMPI_MB_Tracing "Tracing" capability
     is available; otherwise, it shall not be supported.

     MBs may support tracing in such a way that trace level and component
     ID can be used for deciding whether a diagnostic message is actually
     kept versus discarded.

     @param mb Points to a CMPIBroker structure.
     @param level Describes the level of log message. Levels are defined in
         Subclause 5.11(TBD).
     @param component If not NULL, is the implementation-specific component ID.
     @param text If not NULL, points to a string specifying the message text
         to be traced.
     @param string If not NULL, is the message text to
         be output. @p string will be ignored when text is not NULL.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - @p mb or @p string handle is invalid.
     @captracing This function is part of the Tracing MB capability.

     @see CMTraceMessage()
    */
    CMPIStatus (*trace) (const CMPIBroker* mb, CMPILevel level,
        const char* component, const char* text, const CMPIString* string);

#ifdef CMPI_VER_200

    /**
     *   @}
     *   @addtogroup brokerenc-factory
     *   @{
     */

    /**
     @brief Create a new CMPIError object initialized with attributes defined
         by the input parameters.

     CMPIBrokerEncFT.newCMPIError() creates a new CMPIError
     object that is initialized with certain core attributes.

     The input data may (or may not) be defined in a DMTF message
     registry (see @ref ref-dmtf-dsp0228 "DSP0228" for the format of message
     registries, and @ref ref-dmtf-dsp8016 "DSP8016" for the messages defined
     for the MI functions of CMPI).

     @param mb Points to a CMPIBroker structure.
     @param owner A string specifying the value for the OwningEntity attribute
     @param msgID A string which uniquely identifies the
         `MessageID` attribute of the CMPIError object For a description of
         the MessageID attribute, see the description of the
         MessageID property in the CIM_Error class in the CIM
         Schema. If the error message is defined in a DMTF message
         registry, the string value of this argument shall be
         the message ID defined for the message in the registry
         (the concatenation of the values of the PREFIX and
         SEQUENCE_NUMBER attributes of the MESSAGE_ID element for
         the message).
     @param msg A string which represenst the formatted message.
     @param sev The percieved severity of the error.
     @param pc The probably cause of this error
     @param cimStatusCode CIM status code to be associated with this error.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a new CMPIError object.

         The new object will be released automatically by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - @p mb is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the parameters is
         invalid.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @caperrors This function is part of the Extended Errors MB capability.

     @see CMNewCMPIError()
     @added200 Added in CMPI 2.0.0.
     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIError* (*newCMPIError) (const CMPIBroker* mb, const char* owner,
        const char* msgID, const char* msg, const CMPIErrorSeverity sev,
        const CMPIErrorProbableCause pc, const CMPIrc cimStatusCode,
        CMPIStatus* rc);

    /**
     *   @}
     *   @addtogroup brokerenc-misc
     *   @{
     */

    /**
     @brief Open a message file and return a handle to the file.

     If the MB supports message files, CMPIBrokerEncFT.openMessageFile()
     opens a message file and returns a message file handle to that
     file. This function will use the @ref CMPIAcceptLanguage entry from the
     current context to determine the language for the messages, and will
     set the @ref CMPIContentLanguage entry in the current context to the
     language
     that was used. All subsequent calls to CMPIBrokerEncFT.getMessage2()
     using this message file handle will return messages based on
     that language.

     If the MB does not support message files, or if the function fails
     for other reasons, the function returns NULL as the message file handle.
     Subsequent calls to CMPIBrokerEncFT.getMessage2() using the
     NULL message file handle will cause the default message template to be
     used.

     @param mb Points to a CMPIBroker structure.
     @param msgFile
     @parblock
         Points to a string specifying the implementation-specific file path to
         the message file, or a part thereof.

         Examples for such implementation-specific file paths are:
         @li Base name of the message file (does not include file
             extension and directory path). The message file contains
             all languages, and the language is used to locate the
             message in the correct language within the message file.
         @li Base name of the message file (does not include file
             extension and directory path). The message file contains
             messages in only one language, and some identifier for that
             language is part of the base name.
         @li Absolute path of the message file. The message file
             contains all languages, and the language is used to locate
             the message in the correct language within the message
             file.
         @li Absolute path of the message file. The message file
             contains messages in only one language, and some identifier
             for that language is part of the file path.

         The format of the content of the message file is also
         implementation-specific.
     @endparblock
     @param [out] msgFileHandle points to a @ref CMPIMsgFileHandle structure
         that will have been updated with a handle that can be passed to the
         CMPIBrokerEncFT.getMessage2() and CMPIBrokerEncFT.closeMessageFile()
         functions. If the MB supports message files and the function was
         successful, the @ref CMPIMsgFileHandle structure will have been updated
         with a non-NULL handle to the open message file. If the MB does not
         support message files, or if the function failed for other reasons,
         the @ref CMPIMsgFileHandle structure will have been updated with a NULL
         handle.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_FOUND` - The MB supports message files and the
         message file was not found, or the MB does not support message
         files.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p mb handle is invalid.

     @see CMOpenMessageFile()
     @added200 Added in CMPI 2.0.0.
    */
    CMPIStatus (*openMessageFile) (const CMPIBroker* mb, const char* msgFile,
        CMPIMsgFileHandle* msgFileHandle);

    /**
     @brief Close a message file.

     CMPIBrokerEncFT.closeMessageFile() closes a message file
     previously opened by CMPIBrokerEncFT.openMessageFile(). If the message
     file handle is NULL, the message file is not closed, and this is not
     considered a failure.

     @param mb Points to a CMPIBroker structure.
     @param msgFileHandle @p msgFileHandle contains a message file
         handle (including NULL) that was returned by a previous call to
         CMPIBrokerEncFT.openMessageFile().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful (including if the message file
         handle is NULL).
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Either the @p mb or
         @p msgFileHandle handle is invalid.

     @see CMCloseMessageFile()
     @added200 Added in CMPI 2.0.0.
    */
    CMPIStatus (*closeMessageFile) (const CMPIBroker* mb,
        const CMPIMsgFileHandle msgFileHandle);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Get a translated message text from an open message file by
         message ID.

     CMPIBrokerEncFT.getMessage2() gets a translated message text from an open
     message file, by message ID.

     @param mb Points to a CMPIBroker structure.
     @param msgId Points to a string specifying a message ID that is used to
         locate a message template in the open message file.
     @param msgFileHandle Message file handle that was returned by a previous
         call to CMPIBrokerEncFT.openMessageFile(). If the MB supports message
         files, that handle identifies an open message file. If the MB does not
         support message files, that handle is NULL.
     @param defMsg
     @parblock
         Points to a string specifying the default message template that will
         be used when the MB does not support message files or when the
         message ID cannot be located.

         The message template string specified in @p defMsg may contain up to
         ten message insert triggers ($0 through $9). Each insert trigger will
         be expanded; that is, the insert trigger string will be replaced with
         a string representation of the value of the corresponding insert pair
         in the variable arguments of this function. The MI is not affected
         when the MB does not support message files or when the message ID
         cannot be located, because this function still succeeds and returns
         a message with expanded message insert triggers.
     @endparblock
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @param count The number of message insert pairs in the range 0 to 10.
     @param ... The variable arguments of this function are @p count pairs of
         arguments representing the message insert pairs as follows:
         `type, value` whereby @p type is a @ref CMPIType value and @p value
         is a value of that type.
         The following types are supported: @ref CMPI_sint32, @ref CMPI_uint32,
         @ref CMPI_sint64, @ref CMPI_uint64, @ref CMPI_real64,
         @ref CMPI_boolean, @ref CMPI_chars, and @ref CMPI_string.
     @return @parblock
         If successful, a pointer to a new CMPIString object containing either
         the translated or default message will be returned. In both cases, the
         insert triggers will have been expanded.

         If not successful, the default message template without any insert
         triggers expanded will be returned.

         In both cases, the new object will be automatically released by the MB,
         as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.
         Specifically, the MI shall not use CMPIBrokerMemFT.freeString()
         on the new object.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_TYPE_MISMATCH` - Invalid insert pair.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - Count value range violation.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Either the @p mb or @p msgFileHandle
         handle is invalid. Note that NULL is a valid value for the
         @p msgFileHandle handle.
     @captranslation This function is part of the Message Translation
         MB capability.

     @see CMGetMessage2()
     @added200 Added in CMPI 2.0.0.
    */
    CMPIString* (*getMessage2) (const CMPIBroker* mb, const char* msgId,
        const CMPIMsgFileHandle msgFileHandle, const char* defMsg,
        CMPIStatus* rc, CMPICount count, ...);

#endif /*CMPI_VER_200*/

    /**
     *   @}
     *   @addtogroup brokerenc-factory
     *   @{
     */

#ifdef CMPI_VER_210

    /**
     @brief Create a new CIMPropertyList object initialized to a list of
         property names.

     CMPIBrokerEncFT.newPropertyList() creates a new
     CMPIPropertyList that is initialized to a list of property names
     specified by @p properties.

     @param mb Points to a CMPIBroker structure.
     @param properties pointer to the first entry of a
         NULL-terminated array of pointers to C strings that specify the
         property names for the property list.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the new
         CMPIPropertyList object.

         The new object will be automatically released by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p mb handle.

     @added210 Added in CMPI 2.1.0.
    */
    CMPIPropertyList* (*newPropertyList) (const CMPIBroker* mb,
        const char** properties, CMPIStatus* rc);

    /**
     @brief Create a new CMPIString object from a C-language string in a
         specific codepage.

     CMPIBrokerEncFT.newStringCP() creates a new
     CMPIString object that is initialized from a C-language
     string in a specific codepage

     @param mb Points to a CMPIBroker structure.
     @param data Points to a string that is represented in the
         codepage specified in @p cpid. @p data
         is used to initialize the new CMPIString object after
         converting it from its codepage to UTF-8.
     @param cpid specifies the CMPI-specific codepage ID for the
         codepage that is used to interpret the Bytes in the @p data
         argument. See Subclause 5.2.2(TBD) for a list of supported
         codepages and their codepage ID values.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the new
         CMPIString object containing the UTF-8 represented string
         will be returned.

         The new object will be released automatically by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         If the new object is no longer used by the MI, it may be explicitly
         released by the MI using CMPIBrokerMemFT.freeString().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p mb handle is invalid.
     @capcodepage This function is part of the Codepage Conversion
         MB capability.

     @todo KS: Add see macro
     @added210 Added in CMPI 2.1.0.
    */
    CMPIString* (*newStringCP) (const CMPIBroker* mb, const char* data,
        const CMPICodepageID cpid, CMPIStatus* rc);

    /**
     @brief Create a new CMPIEnumerationFilter object initialized with a
         filter query.

     CMPIBrokerEncFT.newEnumerationFilter() creates a new CMPIEnumerationFilter
     object that is initialized with a filter query.

     @param mb Points to a CMPIBroker structure.
     @param filterQueryLanguage Points to a string specifying the query
         language used for @p filterQuery.
         If this argument is NULL, the new CMPIEnumerationFilter object will be
         set to define that no filtering is to be performed.
     @param filterQuery Points to a string specifying a valid query in the
         query language defined by @p filterQueryLanguage.
         If this argument is NULL, the new CMPIEnumerationFilter object will be
         set to define that no filtering is to be performed.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a new CMPIEnumerationFilter object will be
         returned.

         The new object will be released automatically by the MB, as described
         in Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard".
         There is no function to explicitly release the new object.

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p mb handle is invalid.
     @li `CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED` - @p filterQueryLanguage
         defines a query language that the MI does not recognize.
     @li `CMPI_RC_ERR_INVALID_QUERY` - @p filterQuery is not a valid query in
         the specified filter query language.
     @li `CMPI_RC_ERR_QUERY_FEATURE_NOT_SUPPORTED` - A feature of the query
         language is not supported.

     @added210 Added in CMPI 2.1.0.

     @todo TBD KS: In description. What does "set to do no filtering" mean?@n
           AM: It means that it does not restrict anything, i.e. its match()
           always returns true. Do we need a spec update to improve the wording?
    */
    CMPIEnumerationFilter* (*newEnumerationFilter) (const CMPIBroker* mb,
            const char* filterQueryLanguage, const char* filterQuery,
            CMPIStatus* rc);

#endif /*CMPI_VER_210*/

    /**
     *   @}
     */

} CMPIBrokerEncFT;

struct timespec;

/**
 * @brief Function table for MB operating system encapsulation services.
 *
 * This function table is referenced by the CMPIBroker structure, and provides
 * the following operating system encapsulation services:
 * @ref brokerext-lib "Library Resolution",
 * @ref brokerext-thread "POSIX-conformant Threads",
 * @ref brokerext-mutex "POSIX-conformant Mutexes", and
 * @ref brokerext-condition "POSIX-conformant Conditions".
 *
 * @capopsys @parblock
 *     All functions defined in this structure are part of the
 *     OS Encapsulation Services MB capability.
 *
 *     If that capability is not supported, the function pointers in this
 *     function table shall not be NULL, but shall point to a function that can
 *     be called and then indicate back to the caller that it is not supported,
 *     as specified in the description of the function.
 * @endparblock
 */
typedef struct _CMPIBrokerExtFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     *   @addtogroup brokerext-lib
     *   @{
     */

    /**
     @brief Resolve a generic load library name to its file name.

     CMPIBrokerExtFT.resolveFileName() complements a generic dynamic library
     name to its OS-dependent native format.

     @param filename Points to the generic library name,
     @return @parblock
         The returned char* pointer to the
         complemented library name in native OS format.

         Space for this string has been obtained using POSIX ``malloc()`` and
         must be released using POSIX ``free()`` by the caller.
         In case no storage could be obtained for the complemented library
         name, returns NULL.
     @endparblock
    */
    char* (*resolveFileName) (const char* filename);

    /**
     *   @}
     *   @addtogroup brokerext-thread
     *   @{
     */

    /**
     @brief Start a new thread.

     CMPIBrokerExtFT.newThread() starts a new thread,
     using POSIX threading semantics.

     Creating a thread using CMPIBrokerExtFT.newThread() does not inform
     the MB that the current thread will begin using MB functions. Thus,
     @ref CMPIBrokerFT::attachThread "CMPIBrokerFT.attachThread()"
     must be called by the new thread before
     it uses MB functions.

     @param start Points to the function to be started as a thread.
         For details, see type @ref CMPIThreadFunc.
     @param parm Points to argument(s) to be passed to that function.
     @param detached If not zero, defines that the new thread should
         run in detached mode. In detached mode, termination of the
         thread that called this function does not cause the new
         thread to be canceled. See @ref ref-ieee-1003-1 "IEEE 1003.1"
         for details on detached mode.
     @return If successful, the handle of the started thread will be returned.
         If not successful, returns NULL.

     @par Errors
     For historical reasons, no additional error information is passed back.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.

     @todo TBD AM: Done, but please review the new function types:
           @ref CMPIThreadFunc,
           @ref CMPIThreadOnceFunc,
           @ref CMPIThreadKeyCleanupFunc.
    */
    CMPI_THREAD_TYPE (*newThread) (CMPIThreadFunc* start, void* parm,
        int detached);

    /**
     @brief Wait until the specified thread ends.

     CMPIBrokerExtFT.joinThread() suspends the current thread
     until the specified thread ends using the POSIX threading semantics.

     @param thread The thread ID of the thread waiting for completion.
     @param retval Points to the return value of the thread.
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned.

     The Error codes are defined in `errno.h`, specifically for
     the ``pthread_join()`` function; both are defined in
     @ref ref-ieee-1003-1 "IEEE 1003.1".
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.

     @todo KS: Add see macro
    */
    int (*joinThread) (CMPI_THREAD_TYPE thread, CMPI_THREAD_RETURN* retval);

    /**
     @brief Cause current thread to exit with the passed-in return code,

     CMPIBrokerExtFT.exitThread() causes the current thread to exit
     with the passed in return code using POSIX threading semantics.

     The current thread can also exit by simply returning from its thread
     function; the purpose of the CMPIBrokerExtFT.exitThread()
     function is to make premature returns more convenient.

     @param return_code Is the return code that should be used for the thread.
     @return The function never returns, regardless of whether it is
         successful or encounters errors.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.

     @todo KS: Add see macro
    */
    int (*exitThread) (CMPI_THREAD_RETURN return_code);

    /**
     @brief Cancel a running thread.

     CMPIBrokerExtFT.cancelThread() cancels the thread
     identified by @p thread, using POSIX threading
     semantics.

     @param thread The thread to be canceled.
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned.
         Error codes are defined in `errno.h`, specifically for the
         ``pthread_cancel()`` function; both are defined in IEEE 1003.1. The
         ``pthread_cancel()`` function does not define any error codes in
         IEEE 1003.1. Some POSIX implementations use the following error code
         for that function:
          @li `ESRCH` -The specified thread could not be found.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    int (*cancelThread) (CMPI_THREAD_TYPE thread);

    /**
     @brief Suspend execution of current thread for a specified duration.

     CMPIBrokerExtFT.threadSleep() suspends the execution of the
     current thread for the duration specified by @p msec.

     @param msec The suspend duration in milliseconds.
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned.

     Error codes are defined in `errno.h`, defined in IEEE 1003.1.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    int (*threadSleep) (CMPIUint32 msec);

    /**
     @brief Call a function once for a given once-object.

     CMPIBrokerExtFT.threadOnce() executes the specified
     function procedure only once during the lifetime of the
     thread. The once-object is an integer that initially shall
     have a value of zero. The first call to
     CMPIBrokerExtFT.threadOnce() with an initialized
     once-object will call the specified function. On return from
     CMPIBrokerExtFT.threadOnce(), it is guaranteed that the
     specified function has completed, and that the once-object has
     been updated to indicate that. Subsequent calls to
     CMPIBrokerExtFT.threadOnce() by any thread within the
     process with that once-object will not call the specified function.

     @param once Points to the *once-object*. The value of the
         once-object controls whether the specified function has yet to be
         called. The once-object may be located in thread-specific memory
         (that is, each thread has its own separate copy), or in memory
         that is accessible to all threads of the process. The function
         will behave in a thread-safe way. The once-object shall be
         initialized to zero before the first call to the
         CMPIBrokerExtFT.threadOnce() function.
     @param function Points to the function to be invoked.
         For details, see type @ref CMPIThreadOnceFunc.
     @return @parblock
         If successful, zero will be returned.
         If not successful, a non-zero error code will be returned.

         Error codes are defined in `errno.h`, specifically for the
         ``pthread_once()`` function; both are defined in IEEE 1003.1.
     @endparblock
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.

     @todo KS: No macro for this one.
    */
    int (*threadOnce) (int* once, CMPIThreadOnceFunc* function);

    /**
     @brief Create a POSIX threading-conformant thread key for
         accessing the thread local store.

     CMPIBrokerExtFT.createThreadKey() creates a POSIX threading
     conformant thread key. This key can be used as a key to
     access the thread local store.

     @param key Points to the thread key to be returned.
     @param cleanup Points to the function to be invoked during thread local
         store cleanup. For details, see type @ref CMPIThreadKeyCleanupFunc.
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned.
         If successful, zero will be returned.
         Error codes are defined in `errno.h`, specifically for the
         ``pthread_key_create()`` function; both are defined in IEEE
         1003.1.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    int (*createThreadKey) (CMPI_THREAD_KEY_TYPE* key,
        CMPIThreadKeyCleanupFunc* cleanup);

    /**
     @brief Destroy a thread key for accessing the thread local store.

     CMPIBrokerExtFT.destroyThreadKey() destroys a POSIX threading conformant
     thread key for accessing the thread local store.

     @param key The thread key to be destroyed.
     @return @parblock
         If successful, zero will be returned. If not
         successful, a non-zero error code will be returned.

         Error codes are defined in `errno.h`, specifically for the
         ``pthread_key_delete()`` function; both are defined in IEEE 1003.1.
     @endparblock
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    int (*destroyThreadKey) (CMPI_THREAD_KEY_TYPE key);

    /**
     @brief Get a data pointer from the thread local store using a thread key.

     CMPIBrokerExtFT.getThreadSpecific() gets a data
     pointer from the thread local store using a POSIX
     threading-conformant thread key.

     @param key The key to be used to retrieve the data pointer.
     @return If successful, returns the data pointer.
         If not successful, returns NULL.

     @par Errors
     For historical reasons, no additional error information is passed back.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    void* (*getThreadSpecific) (CMPI_THREAD_KEY_TYPE key);

    /**
     @brief Set a data pointer in the thread local store using a thread key.

     CMPIBrokerExtFT.setThreadSpecific() sets a data pointer in the thread
     local store using a POSIX threading-conformant  thread key.

     @param key The key to be used.
     @param value The data pointer that is stored in the thread local store.
     @return @parblock
         If successful, returns zero.

         If not successful, returns a non-zero error code. Error
         codes are defined in `errno.h`, specifically for the
         ``pthread_setspecific()`` function; both are defined in
         @ref ref-ieee-1003-1 "IEEE 1003.1".
     @endparblock
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.

     @todo KS: No macro for this one.
    */
    int (*setThreadSpecific) (CMPI_THREAD_KEY_TYPE key, void* value);

    /**
     *   @}
     *   @addtogroup brokerext-mutex
     *   @{
     */

    /**
     @brief Create a POSIX thread conformant mutex.

     CMPIBrokerExtFT.newMutex() creates a POSIX threading
     conformant recursive mutex.

     The mutex that is created shall exhibits the following behavior:
     @li For locking a locked mutex: A thread that holds a lock on a
     mutex and attempts to lock that mutex again without first
     unlocking it shall succeed in locking the mutex. Multiple
     locks of the mutex (by the same thread) shall require the same
     number of unlocks (by that same thread) to release the mutex
     before another thread can acquire the mutex.
     @li For unlocking an unlocked mutex: A thread attempting to
     unlock a mutex that is not locked by that thread (that is, the
     mutex is either entirely unlocked or locked by another thread)
     shall fail in unlocking the mutex.

     This behavior is consistent with mutex type PTHREAD_MUTEX_RECURSIVE
     defined in IEEE 1003.1.

     @param opt For future use. It should be ignored by the MB, and
         MIs should pass a value of 0
     @return If successful, returns the handle of the new mutex.
         If not successful, returns NULL.

     @par Errors
     For historical reasons, no additional error information is passed back.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    CMPI_MUTEX_TYPE (*newMutex) (int opt);

    /**
     @brief Destroy a POSIX threading-conformant mutex. (**Deprecated**)

     CMPIBrokerExtFT.destroyMutex() destroys a POSIX threading conformant
     mutex.

     @param mutex The mutex to be destroyed.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
     @deprecated This function is deprecated since CMPI 2.1,
         because it does not indicate whether it succeeded or failed. Use
         CMPIBrokerExtFT.destroyMutex2() instead.
    */
    void (*destroyMutex) (CMPI_MUTEX_TYPE mutex);

    /**
     @brief Lock a POSIX threading-conformant mutex. (**Deprecated**)

     CMPIBrokerExtFT.lockMutex() locks a POSIX threading-conformant mutex.

     If the mutex is locked by another thread, the current thread is suspended
     until the lock is granted. The behavior in case the mutex is already
     locked by the current thread is defined in the description of
     CMPIBrokerExtFT.newMutex().

     @param mutex The mutex to be locked.
     @return None.

     @par Errors
     For historical reasons, this function does not indicate whether it
     succeeded or failed.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
     @deprecated This function is deprecated since CMPI 2.1,
         because it does not indicate whether it succeeded or failed.
         Use CMPIBrokerExtFT.lockMutex2() instead.
    */
    void (*lockMutex) (CMPI_MUTEX_TYPE mutex);

    /**
     @brief Unlock a POSIX threading-conformant mutex. (**Deprecated**)

     CMPIBrokerExtFT.unlockMutex() releases control of the mutex.

     The behavior in case the mutex is not
     locked by the current thread is defined in the description of
     CMPIBrokerExtFT.newMutex().

     @param mutex The mutex to be unlocked.
     @return None.

     @par Errors
     For historical reasons, this function does not indicate whether it
     succeeded or failed.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
     @deprecated This function is deprecated since CMPI 2.1,
         because it does not indicate whether it succeeded or failed.
         Use CMPIBrokerExtFT.unlockMutex2() instead.
    */
    void (*unlockMutex) (CMPI_MUTEX_TYPE mutex);

    /**
     *   @}
     *   @addtogroup brokerext-condition
     *   @{
     */

    /**
     @brief Create a new condition variable.

     CMPIBrokerExtFT.newCondition() creates a new POSIX threading-conformant
     condition variable.

     @param opt for future use. It should be ignored by the MB, and MIs
         should pass a value of 0.
     @return If successful, handle of newly created condition
         variable. If not successful, NULL.

     @par Errors
     For historical reasons, no additional error information is passed back.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    CMPI_COND_TYPE (*newCondition) (int opt);

    /**
     @brief Destroy a condition variable. (**Deprecated**)

     CMPIBrokerExtFT.destroyCondition() destroys a POSIX threading conformant
     condition variable. (**Deprecated**)

     @param cond The condition variable to be destroyed.
     @return None.

     @par Errors
     For historical reasons, this function does not indicate whether it
     succeeded or failed.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
     @deprecated This function is deprecated since CMPI 2.1,
         because it does not indicate whether it succeeded or failed. Use
         CMPIBrokerExtFT.destroyCondition2() instead.
    */
    void (*destroyCondition) (CMPI_COND_TYPE cond);

    /**
     @brief Wait until condition is signalled.

     CMPIBrokerExtFT.condWait() waits until the condition has been
     signalled. If the condition variable has been signalled already, the
     function returns immediately; otherwise, it suspends the current thread
     to wait for the signal and then returns.

     @param cond The handle of the condition variable to be used.
     @param mutex The handle of a locked mutex guarding this
         condition variable.
     @return If successful, zero will be returned.
        If not successful, returns a non-zero error code will be returned.
        Error codes are defined in `errno.h`, specifically for the
        ``pthread_cond_wait()`` function; both are defined in IEEE 1003.1.
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    int (*condWait) (CMPI_COND_TYPE cond, CMPI_MUTEX_TYPE mutex);

    /**
     @brief Wait until the condition is signalled or a timeout value expires.

     CMPIBrokerExtFT.timedCondWait() waits until a POSIX
     threading-conformant condition variable is signalled. If the condition
     variable has been signalled already, the function returns immediately;
     otherwise, it suspends the current thread to wait for the signal and
     then returns. The function returns when the timeout expires before the
     condition is signalled.

     @param cond Specifies the handle of the condition variable to be used.
     @param mutex Specifies the handle of a locked mutex guarding
         this condition variable.
     @param wait Specifies the timeout value.
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned. Error
         codes are defined in `errno.h`, specifically for the
         ``pthread_cond_timedwait()`` function; both are defined in
         @ref ref-ieee-1003-1 "IEEE 1003.1".
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    int (*timedCondWait) (CMPI_COND_TYPE cond, CMPI_MUTEX_TYPE mutex,
        struct timespec* wait);

    /**
     @brief Send a signal to a condition variable.

     CMPIBrokerExtFT.signalCondition() sends a signal
     to a POSIX threading-conformant condition variable.

     @param cond Specifies the handle of the condition variable to
         send the signal.
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned. Error
         codes are defined in `errno.h`, specifically for the
         ``pthread_cond_signal()`` function; both are defined in
         @ref ref-ieee-1003-1 "IEEE 1003.1".
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
    */
    int (*signalCondition) (CMPI_COND_TYPE cond);

    /**
     *   @}
     *   @addtogroup brokerext-mutex
     *   @{
     */

#ifdef CMPI_VER_210

    /**
     @brief Destroy a POSIX threading-conformant mutex.

     CMPIBrokerExtFT.destroyMutex2() destroys a POSIX threading conformant
     mutex.

     This function superceedes the original CMPIBrokerExtFT.destroyMutex()
     function.

     @param mutex The mutex to be destroyed.
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned. Error codes
         are defined in `errno.h`, specifically for the
         ``pthread_mutex_destroy()`` function; both are defined in
         @ref ref-ieee-1003-1 "IEEE 1003.1".
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
     @added210 Added in CMPI 2.1.0.
    */
    int (*destroyMutex2) (CMPI_MUTEX_TYPE mutex);

    /**
     @brief Lock a POSIX threading-conformant mutex.

     CMPIBrokerExtFT.lockMutex2() locks a POSIX threading conformant mutex.
     If the mutex is locked by another
     thread, the current thread is suspended until the lock is granted.
     The behavior in case the mutex is already locked by the current thread
     is defined in the description of CMPIBrokerExtFT.newMutex().

     This function superceedes the original CMPIBrokerExtFT.lockMutex()
     function.

     @param mutex The mutex to be locked.
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned. Error codes
         are defined in `errno.h`, specifically for the
         ``pthread_mutex_lock()`` function; both are defined in
         @ref ref-ieee-1003-1 "IEEE 1003.1".
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
     @added210 Added in CMPI 2.1.0, superceeding the deprecated
         CMPIBrokerExtFT.lockMutex() function.
    */
    int (*lockMutex2) (CMPI_MUTEX_TYPE mutex);

    /**
     @brief Unlock a POSIX threading-conformant mutex.

     CMPIBrokerExtFT.unlockMutex2() unlocks a POSIX
     threading conformant mutex. The behavior in case the mutex
     is not locked by the current thread is defined in the description of
     CMPIBrokerExtFT.newMutex().

     This function superceedes the original CMPIBrokerExtFT.unlockMutex()
     function.

     @param mutex TBD
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned. Error codes
         are defined in `errno.h`, specifically for the
         ``pthread_mutex_lock()`` function; both are defined in
         @ref ref-ieee-1003-1 "IEEE 1003.1".
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.
     @added210 Added in CMPI 2.1.0.
    */
    int (*unlockMutex2) (CMPI_MUTEX_TYPE mutex);

    /**
     *   @}
     *   @addtogroup brokerext-condition
     *   @{
     */

    /**
     @brief Destroy a POSIX threading-conformant condition variable.

     CMPIBrokerExtFT.destroyCondition2() destroys a POSIX
     threading-conformant condition variable.

     This function superceedes the original
     CMPIBrokerExtFT.destroyCondition() function.

     @param cond TBD
     @return If successful, zero will be returned.
         If not successful, a non-zero error code will be returned. Error codes
         are defined in `errno.h`, specifically for the
         ``pthread_cond_destroy()`` function; both are defined in
         @ref ref-ieee-1003-1 "IEEE 1003.1".
     @capopsys This function is part of the OS Encapsulation Services MB
         capability.

     @todo KS: There is no macro for any of the condition functions
     @added210 Added in CMPI 2.1.0.
    */
    int (*destroyCondition2) (CMPI_COND_TYPE cond);

#endif /*CMPI_VER_210*/

    /**
     *   @}
     */

} CMPIBrokerExtFT;

#ifdef CMPI_VER_200

/**
 * @brief Function table for MB memory enhancement services.
 *
 * This function table is referenced by the CMPIBroker structure, and provides
 * @ref brokermem-all "Memory Enhancement Services".
 *
 * @capmemory This function table is part of the Memory Enhancement Services
 *     MB capability.
 * @added200 Added in CMPI 2.0.0.
 */
typedef struct _CMPIBrokerMemFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     *   @addtogroup brokermem-all
     *   @{
     */

    /**
     @brief Mark a new object lifecycle level for subsequent newly created
         CMPI encapsulated data type objects.

     CMPIBrokerMemFT.mark() marks a new object lifecycle level for the
     calling MI. Subsequent newly created CMPI encapsulated data type objects
     in that MI will be associated with that new object lifecycle level.
     A subsequent invocation of CMPIBrokerMemFT.release()
     with the returned @ref CMPIGcStat pointer will release only the
     objects associated with that object lifecycle level.

     The mark() and release() function calls may be stacked.

     Stacked object lifecycle levels shall not overlap.

     @param mb Points to a CMPIBroker structure.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a @ref
         CMPIGcStat structure, for use with CMPIBrokerMemFT.release().

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.
    */
    CMPIGcStat* (*mark) (const CMPIBroker* mb, CMPIStatus* rc);

    /**
     @brief Release all CMPI encapsulated data type objects created at the
         specified object lifecycle level, and remove that level.

     CMPIBrokerMemFT.release() releases all CMPI encapsulated data type
     objects created
     other than with `clone()` at the specified object lifecycle
     level, and removes that object lifecycle level. This indicates
     to the MB that these objects (including any objects they
     contain) will no longer be used by the MI. The MB may free the
     resources associated with these objects during the call to this
     function, or later during some garbage collection cycle.

     The mark() and release() function calls may be stacked.

     @param mb Points to a CMPIBroker structure.
     @param gc The handle returned from the mark() operation.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @see CMRelease()
    */
    CMPIStatus (*release) (const CMPIBroker* mb, const CMPIGcStat* gc);

    /**
     @brief Allocate an uninitalized memory block of specified size.

     CMPIBrokerMemFT.cmpiMalloc() allocates an uninitalized memory block of
     the specified size. This function behaves consistently with the
     POSIX `` malloc()`` function (see @ref ref-ieee-1003-1 "IEEE 1003.1").

     The allocated memory block can be explicitly released by the MI using
     CMPIBrokerMemFT.cmpiFree(), or will be
     automatically released by the MB after cleanup of the MI.

     @param mb Points to a CMPIBroker structure.
     @param size Specifies the amount of memory to allocate in Bytes.
     @return Returns a pointer to the allocated memory, or NULL if the memory
         could not be allocated. No additional error information is returned.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void* (*cmpiMalloc) (const CMPIBroker* mb, size_t size);

    /**
     @brief Change the size of a memory block.

     CMPIBrokerMemFT.cmpiCalloc() changes the size of the memory block
     pointed to by ptr which had been returned by a previous call to
     CMPIBrokerMemFT.cmpiMalloc() or
     CMPIBrokerMemFT.cmpiCalloc().
     This function behaves consistently with the POSIX ``realloc()`` function
     (see @ref ref-ieee-1003-1 "IEEE 1003.1").

     The function may move the memory block to a new location (whose address
     is returned by the function). The content of the memory block is
     preserved up to the lesser of the new and old sizes, even if the
     block is moved to a new location. If the new size is larger, the value
     of the newly allocated portion is indeterminate.

     @param mb Points to a CMPIBroker structure.
     @param nElems The number of elements to allocate.
     @param sizeElem The size of each element to allocate.
     @return Returns a pointer to the allocated memory, or NULL if the memory
         could not be allocated. No additional error information is returned.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void* (*cmpiCalloc) (const CMPIBroker* mb, size_t nElems, size_t sizeElem);

    /**
     @brief Change the size of a memory block.

     CMPIBrokerMemFT.cmpiRealloc() changes the size of the memory block
     pointed to by @p ptr which had been returned by a previous call to
     CMPIBrokerMemFT.cmpiMalloc() or
     CMPIBrokerMemFT.cmpiCalloc().
     This function behaves consistently with the POSIX ``realloc()`` function
     (see @ref ref-ieee-1003-1 "IEEE 1003.1").

     The function may move the memory block to a new location (whose address
     is returned by the function). The content of the memory block is
     preserved up to the lesser of the new and old sizes, even if the
     block is moved to a new location. If the new size is larger, the value
     of the newly allocated portion is indeterminate.

     @param mb Points to a CMPIBroker structure.
     @param ptr Points to previosuly allocated memory.  Passing a pointer
         to this function which was not allocated explicitly by cmpiMalloc()
         or cmpiCalloc() is undefined.
     @param size The new size of the memory block in Bytes.
     @return If successful, a pointer to the resized allocated memory block
         NULL if the new memory is not allcoated. If the function fails
         the original @p ptr argument is unchanged.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void* (*cmpiRealloc) (const CMPIBroker* mb, void* ptr, size_t size);

    /**
     @brief Allocate a memory block and initialize it with a string.

     CMPIBrokerMemFT.cmpiStrDup() allocates a memory
     block and initializes it by copying a C-language string into it. This
     function behaves consistently with the POSIX ``strdup()`` function
     (see @ref ref-ieee-1003-1 "IEEE 1003.1").
     The allocated memory block can be explicitly
     released by the MI using CMPIBrokerMemFT.cmpiFree(), or will be
     automatically released by the MB after cleanup of the MI.

     @param mb Points to a CMPIBroker structure.
     @param str The C-language string to duplicate.
     @return Pointer to the new memory block (that is, to the new
         C-language string), or NULL if unsuccessful.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    char* (*cmpiStrDup) (const CMPIBroker* mb, const char* str);

    /**
     @brief Free a memory block.

     CMPIBrokerMemFT.cmpiFree() releases a memory block allocated via
     CMPIBrokerMemFT.cmpiMalloc(), CMPIBrokerMemFT.cmpiCalloc(), or
     CMPIBrokerMemFT.cmpiRealloc().

     This function behaves consistently with the POSIX ``free()`` function
     (see @ref ref-ieee-1003-1 "IEEE 1003.1").
     This indicates to the MB that the memory block will
     no longer be used by the MI. The MB may free (=reclaim) the memory
     block during the call to this function, or later during some garbage
     collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").
     Memory blocks that have not been explicitly released that way, will be
     automatically released after cleanup of the MI.

     @param mb Points to a CMPIBroker structure.
     @param ptr The memory to free. This memory MUST have been allocated via
         the CMPIBrokerMemFT.cmpiMalloc(), CMPIBrokerMemFT.cmpiCalloc(), or
         CMPIBrokerMemFT.cmpiRealloc() functions.
     @return None. Does not indicate whether it succeeded or failed.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void (*cmpiFree) (const CMPIBroker* mb, void* ptr);

    /**
     @brief Release a CMPIInstance object.

     CMPIBrokerMemFT.freeInstance() releases a CMPIInstance object.
     This indicates to the
     MB that the object (including any objects it contains) will no
     longer be used by the MI. The MB may free the resources
     associated with the object during the call to this function, or
     later during some garbage collection cycle.

     Allows a MI to free memory associated to a CMPIInstance
     which was allocated via CMPIBrokerEncFT.newInstance().
     this function should be called when an instance is no longer
     being used by the MI. This function will free all contained
     objects (e.g. properties).

     @param mb Points to a CMPIBroker structure.
     @param inst Points to the CMPIInstance object to be released.
         This object shall have been created via CMPIBrokerEncFT.newInstance().
     @return None. Does not indicate whether it succeeded or failed.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void (*freeInstance) (const CMPIBroker* mb, CMPIInstance* inst);

    /**
     @brief Release a CMPIObjectPath object.

     CMPIBrokerMemFT.freeInstance() releases a
     CMPIObjectPath object. This indicates to the MB that the object
     (including any objects it contains) will no longer be used by the MI.
     The MB may free the resources associated with the object during the call
     to this function, or later during some garbage collection cycle.

     Allows a MI to free memory associated to a
     CMPIObjectPath which was allocated via CMPIBrokerEncFT.newObjectPath().
     This function should
     be called when a CMPIObjectPath is no longer being
     used by the MI. This function will free all contained objects.

     @param mb Points to a CMPIBroker structure.
     @param obj Points to the CMPIObjectPath object that is to be released.
         This object shall have been created via
         CMPIBrokerEncFT.newObjectPath().
     @return None.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void (*freeObjectPath) (const CMPIBroker* mb, CMPIObjectPath* obj);

    /**
     @brief Release a CMPIArgs object.

     CMPIBrokerMemFT.freeArgs() releases a CMPIArgs object.
     This indicates to the MB that the object (including any objects it
     contains) will no longer be used by the MI. The MB may free (=reclaim)
     the memory associated with the object during the call to this function,
     or later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param mb Points to a CMPIBroker structure.
     @param args Points to the CMPIArgs object to be released.
         This object shall have been created via CMPIBrokerEncFT.newArgs().
     @return None.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.
    */
    void (*freeArgs) (const CMPIBroker* mb, CMPIArgs* args);

    /**
     @brief Release a CMPIString object.

     CMPIBrokerMemFT.freeString() releases a CMPIString object.
     This indicates to the MB that the object (including any objects it
     contains) will no longer be used by the MI. The MB may free (=reclaim)
     the memory associated with the object during the call to this function,
     or later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     Allows an MI to free memory associated to a CMPIString which was
     allocated via CMPIBrokerEncFT.newString().
     This function should be called when an instance is no longer being used
     by the MI.

     @param mb Points to a CMPIBroker structure.
     @param args The string to free.
     @return None.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void (*freeString) (const CMPIBroker* mb, CMPIString* str);

    /**
     @brief Release a CMPIArray object.

     CMPIBrokerMemFT.freeArray() releases a CMPIArray object.
     This indicates to the MB that the object (including any objects it
     contains) will no longer be used by the MI. The MB may free (=reclaim)
     the memory associated with the object during the call to this function,
     or later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     Allows a MI to free memory associated to a CMPIArray which was
     allocated via CMPIBrokerEncFT.newArray(). This function should
     be called when an instance is no longer being used by the MI. This
     function will free all contained objects (e.g. the array elements).

     @param mb Points to a CMPIBroker structure.
     @param array Points to the CMPIArray object that is to be
         released. This object shall have been created via
         CMPIBrokerEncFT.newArray().
     @return None.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void (*freeArray) (const CMPIBroker* mb, CMPIArray* array);

    /**
     @brief Release a CMPIDateTime object.

     CMPIBrokerMemFT.freeDateTime() releases a
     CMPIDateTime object. This indicates to the MB that the object
     (including any objects it contains) will no longer be used by
     the MI. The MB may free (=reclaim) the memory associated with
     the object during the call to this function, or later during
     some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     Allows a MI to free memory associated to a CMPIDateTime which was
     allocated via CMPIBrokerEncFT.newDateTime(). This function
     should be called when an instance is no longer being used by the MI.
     This function will free all contained objects.

     @param mb Points to a CMPIBroker structure.
     @param dt Points to the CMPIDateTime object that is to be released.
         This object shall have been created via CMPIBrokerEncFT.newDateTime().
     @return None.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.

     @todo KS: Add see macro
    */
    void (*freeDateTime) (const CMPIBroker* mb, CMPIDateTime* dt);

    /**
     @brief Release a CMPISelectExp object.

     CMPIBrokerMemFT.freeSelectExp() releases a
     CMPISelectExp object. This indicates to the MB that the object
     (including any objects it contains) will no longer be used by
     the MI. The MB may free (=reclaim) the memory associated with
     the object during the call to this function, or later during
     some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     Allows a MI to free memory associated to a CMPISelectExp which was
     allocated via CMPIBrokerEncFT.newSelectExp(). This function
     should be called when an instance is no longer being used by the MI.

     This function will free all contained objects.

     @param mb Points to a CMPIBroker structure.
     @param se Points to the CMPISelectExp object to be released.
         This object shall have been created via CMPIBrokerEncFT.newSelectExp().
     @return None.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability but can be implemented only if the Query Normalization MB
         capability is supported as well.

     @todo KS: Add see macro
    */
    void (*freeSelectExp) (const CMPIBroker* mb, CMPISelectExp* se);

#ifdef CMPI_VER_210

    /**
     @brief Free the memory of a C-language string.

     CMPIBrokerMemFT.freeChars() releases a C-language string.
     This indicates to the MB that the string will
     no longer be used by the MI. The MB may free (=reclaim) the memory
     associated with the string during the call to this function, or later
     during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     This function shall be supported by the MB if the
     @ref CMPI_MB_CodepageConversion "Codepage Conversion" capability
     is available; otherwise, it shall not be supported.

     @param mb Points to a CMPIBroker structure.
     @param chars Points to the C-language string to be released.
         This C-language string shall have been created via
         CMPIStringFT.newCharsCP().
     @return None.
     @capmemory This function is part of the Memory Enhancement Services MB
         capability.
     @added210 Added in CMPI 2.1.0.
    */
    void (*freeChars) (const CMPIBroker* mb, char* chars);

#endif /*CMPI_VER_210*/

    /**
     *   @}
     */

} CMPIBrokerMemFT;

#endif /*CMPI_VER_200*/

/**
 * @}
 * @addtogroup edt-context
 * @{
 */

/**
 * @brief CMPIContext encapsulated data type object.
 *
 * CMPIContext objects are used by the MB to pass context data about the
 * invoked operation to the MI.
 *
 * The context data consists of named entries. See
 * @ref def-context-fieldnames "Names of CMPIContext fields" for defined names.
 *
 * @capcontext This encapsulated data type is part of the Context Data
 *     MB capability.
 */
typedef struct _CMPIContext {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIContextFT* ft;

} CMPIContext;

/**
 * @brief Function table of CMPIContext encapsulated data type object.
 */
typedef struct _CMPIContextFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIContext object.

     CMPIContextFT.release() releases a CMPIContext object.

     This indicates to the MB that the object (including any objects it
     contains) will no longer be used by the MI. The MB may free (=reclaim)
     the memory associated with the object during the call to this function,
     or later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param ctx Points to the CMPIContext object for this function.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIContext* ctx);

    /**
     @brief Create an independent copy of a CMPIContext object.

     CMPIContextFT.clone() creates an independent copy of the
     CMPIContext object.

     @param ctx Points to the CMPIContext object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the copied CMPIContext
         object will be returned.

         The returned CMPIContext object shall be explicitly released by the MI
         using CMPIContextFT.release().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.

     @see CMClone()
    */
    CMPIContext* (*clone) (const CMPIContext* ctx, CMPIStatus* rc);

    /**
     @brief Get a context entry in a CMPIContext object by name.

     CMPIContextFT.getEntry() gets a context entry in a
     CMPIContext object by supplying its name.

     @param ctx Points to the CMPIContext object for this function.
     @param name string specifying the context entry name.
         See @ref def-context-fieldnames "Names of CMPIContext fields"
         for defined names
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPIData structure containing the
         specified context entry will be returned.

         If not successful, CMPIData.state will have the @ref CMPI_badValue
         flag set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Entry not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.

     @see CMGetContextEntry()
    */
    CMPIData (*getEntry) (const CMPIContext* ctx, const char* name,
        CMPIStatus* rc);

    /**
     @brief Get a context entry in a CMPIContext object by index.

     CMPIContextFT.getEntryAt() gets a Context entry value defined
     by its index.

     @param ctx Points to the CMPIContext object for this function.
     @param index Specifies the zero-based position of the
         context entry in the internal data array. The order of
         context entries in the internal data array is
         implementation-defined.
     @param [out] name
     @parblock
         If not NULL, points to a CMPIString pointer that upon
         success will have been updated to point to a CMPIString object
         containing the name of the returned context entry.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPIContext
         object which will be released along with that object, or a new object
         created by the MB which will be automatically released by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").
     @endparblock
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIData structure
         containing the specified context entry.

         If not successful, CMPIData.state will have the @ref CMPI_badValue
         flag set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Entry not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.

     @see CMGetContextEntryAt()
    */
    CMPIData (*getEntryAt) (const CMPIContext* ctx, CMPICount index,
        CMPIString** name, CMPIStatus* rc);

    /**
     @brief Get the number of context entries in a CMPIContext object.

     CMPIContextFT.getEntryCount() gets the number of entries
     contained in this CMPIContext.

     @param ctx Points to the CMPIContext object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPICount value indicating the number
         of entries in the CMPIContext object.

         If not successful, the return value will be undefined.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Entry not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.

     @see CMGetContextEntryCount()
    */
    CMPICount (*getEntryCount) (const CMPIContext* ctx, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Add or replace a context entry in a CMPIContext object.

     CMPIContextFT.addEntry() adds or replaces a context entry in a CMPIContext
     object.

     @param ctx Points to the CMPIContext object for this function.
     @param name Points to a string specifying the context entry name.
         See @ref def-context-fieldnames "Names of CMPIContext fields"
         for defined names.
     @param value Points to a CMPIValue structure containing the non-NULL value
         to be assigned to the context entry, or NULL to specify that NULL is
         to be assigned.
     @param type
     @parblock
         @ref CMPIType value specifying the type of the value to be assigned to
         the context entry.

         If the value of @p type is @ref CMPI_chars or @ref CMPI_charsA, the
         C-language string to which the @p chars member of @p value points is
         copied by this function and the original string memory may be freed
         by the MI right after this function returns.
     @endparblock
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_DATA_TYPE` - Type not supported for this call, or
         type is not recognized.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.

     @see CMAddContextEntry()
    */
    CMPIStatus (*addEntry) (const CMPIContext* ctx, const char* name,
        const CMPIValue* value, const CMPIType type);

} CMPIContextFT;

/**
 * @}
 * @addtogroup edt-result
 * @{
 */

/**
 * @brief CMPIResult encapsulated data type object.
 */
typedef struct _CMPIResult {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIResultFT* ft;

} CMPIResult;

/**
 * @brief Function table of CMPIResult encapsulated data type object.
 */
typedef struct _CMPIResultFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIResult object.

     CMPIResultFT.release() releases a CMPIResult object.
     This indicates to the MB that
     the object (including any objects it contains) will no longer
     be used by the MI. The MB may free the resources associated with
     the object during the call to this function, or later during
     some garbage collection cycle.

     @param rslt Points to the CMPIResult object to be released.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p rslt handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIResult* rslt);

    /**
     @brief Create an independent copy of a CMPIResult object.

     CMPIResultFT.clone() creates an independent copy of the
     CMPIResult object defined by @p rslt.

     @param rslt Points to the CMPIResult object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the
         copied CMPIPropertyList object.

         The returned CMPIResult object shall be explicitly released by
         the MI using CMPIResultFT.release().

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p rslt handle is invalid.

     @see CMClone()
    */
    CMPIResult* (*clone) (const CMPIResult* rslt, CMPIStatus* rc);

    /**
     @brief Add a value/type pair to a CMPIResult object.

     CMPIResultFT.returnData() adds a value/type pair to be
     returned to the MB, to a CMPIResult object.

     @param rslt Points to the CMPIResult object for this function.
     @param value Points to CMPIValue structure specifying the non-NULL value
         to be returned, or is NULL to specify that NULL is to be returned
     @param type CMPIType value specifying the type to be returned.
         If the value of @p type is @ref CMPI_chars or
         @ref CMPI_charsA, the C-language string to which the @p chars member
         of @p value points is copied by this function and the
         original string memory may be freed by the MI right after this
         function returns.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_DATA_TYPE` - An attempt to return a data type
         that is not allowed for this MI function invocation
         or @p type is not recognized.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p rslt handle is invalid
         or NULL, or the MB has aborted the request operation for which
         this data is being returned.

     @see CMReturnData()
    */
    CMPIStatus (*returnData) (const CMPIResult* rslt, const CMPIValue* value,
        const CMPIType type);

    /**
     @brief Add an instance to a CMPIResult object.

     CMPIResultFT.returnInstance() adds an instance to be returned to the MB,
     to a CMPIResult object.

     @param rslt Points to the CMPIResult object for this function.
     @param inst Instance to be returned.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p rslt handle is invalid
         or the MB has aborted the request for which this data
         is returned.

     @see CMReturnInstance()
    */
    CMPIStatus (*returnInstance) (const CMPIResult* rslt,
        const CMPIInstance* inst);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Add an object path to a CMPIResult object.

     CMPIResultFT.returnObjectPath() adds an object path to be returned to the
     MB, to a CMPIResult object.

     @param rslt Points to the CMPIResult object for this function.
     @param op Points to a CMPIObjectPath object representing the object path
         to be returned.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p rslt handle is invalid, or the
         MB has aborted the request for which this data is being returned.

     @see CMReturnObjectPath()
    */
    CMPIStatus (*returnObjectPath) (const CMPIResult* rslt,
        const CMPIObjectPath* op);

    /**
     @brief Indicate that no more items will be added to a CMPIResult object.

     CMPIResultFT.returnDone() indicates to the MB that
     no further items will be added to a CMPIResult object; that
     is, the MI will not return any more data to the MB.

     @param rslt Points to the CMPIResult object for this function.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p rslt handle is invalid
         or the MB has aborted the request for which this data is returned.

     @see CMReturnDone()
    */
    CMPIStatus (*returnDone) (const CMPIResult* rslt);

#ifdef CMPI_VER_200

    /**
     @brief Add an error to a CMPIResult object.

     CMPIResultFT.returnError() adds an error to be returned to the MB, to a
     CMPIResult object.

     In WBEM protocols that support multiple extended errors in an error
     response, the MB shall represent the extended errors in the protocol in
     the order of calls to this function. In WBEM protocols that support only
     one extended error in an error response, the MB shall represent the
     extended error from the first call to this function for a particular
     result.

     @param rslt Points to the CMPIResult object for this function.
     @param er Points to a CMPIError object representing the error to be
         returned. This function may be called multiple times, each time adding
         one CMPIError object to the set of extended errors for this result.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p rslt handle is invalid
         or the MB has aborted the request for which this data is returned.
     @caperrors This function is part of the Extended Errors MB capability.

     @see CMReturnError()
     @added200 Added in CMPI 2.0.0.
    */
    CMPIStatus (*returnError) (const CMPIResult* rslt, const CMPIError* er);

#endif /*CMPI_VER_200*/

} CMPIResultFT;

/**
 * @}
 * @addtogroup edt-error
 * @{
 */

#ifdef CMPI_VER_200

/**
 * @brief CMPIError encapsulated data type object.
 *
 * @caperrors This encapsulated data type is part of the Extended Errors
 *     MB capability.
 *
 * @added200 Added in CMPI 2.0.0.
 * @required210 Required to be supported since CMPI 2.1.0.
 */
typedef struct _CMPIError {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIErrorFT* ft;

} CMPIError;

/**
 * @brief Function table of CMPIError encapsulated data type object.
 *
 * @added200 Added in CMPI 2.0.0.
 * @required210 Required to be supported since CMPI 2.1.0.
 */
typedef struct _CMPIErrorFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

// DONE_AM Next function is already synced with spec.
    /**
     @brief Release a CMPIError object.

     CMPIErrorFT.release() releases a CMPIError object.

     This indicates to the MB that the object (including any objects it
     contains) will no longer be used by the MI. The MB may free (=reclaim) the
     memory associated with the object during the call to this function, or
     later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param er Points to the CMPIError object to be released.
         That object shall have been created using CMPIErrorFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - @p er is invalid.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @see CMRelease()
     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*release) (CMPIError* er);

    /**
     @brief Create an independent copy of a CMPIError object.

     CMPIErrorFT.clone() creates an independent copy of a CMPIError object.

     @param er Points to the CMPIError object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the copied CMPIError object will be
         returned. The returned CMPIError object shall be explicitly released
         by the MI using CMPIErrorFT.release().

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @see CMClone()
     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIError* (*clone) (const CMPIError* er, CMPIStatus* rc);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Get the `ErrorType` attribute of a CMPIError object.

     CMPIErrorFT.getErrorType() gets the value of the `ErrorType` attribute
     in a CMPIError object.

     For a description of the `ErrorType` attribute, see @ref CMPIErrorType
     and the description of the `ErrorType` property in the `CIM_Error` class
     in the CIM Schema.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a @ref CMPIErrorType enumeration value will be returned,
         indicating the value of the `ErrorType` attribute of the CMPIError
         object.

         If not successful, the returned value is undefined.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @see CMGetErrorType()
     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIErrorType (*getErrorType) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Get the `OtherErrorType` attribute of a CMPIError object.

     CMPIErrorFT.getOtherErrorType() gets the value of the `OtherErrorType`
     attribute of a CMPIError object.

     For a description of the `OtherErrorType` attribute, see the description of
     the `OtherErrorType` property in the `CIM_Error` class in the CIM Schema.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `OtherErrorType` attribute of the
         CMPIError object is non-NULL, returns a pointer to a CMPIString object,
         indicating the value of the `OtherErrorType` attribute of the CMPIError
         object.

         Otherwise, returns NULL.

         The caller must inspect the function return status to see whether the
         function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @see CMGetOtherErrorType()
     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIString* (*getOtherErrorType) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Get the `OwningEntity` attribute of a CMPIError object.

     CMPIErrorFT.getOwningEntity() returns a string which describes the
     owning entity.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `OwningEntity` attribute of the
         CMPIError object is non-NULL, a pointer to a CMPIString object will be
         returned, indicating the value of the `OwningEntity` attribute of the
         CMPIError object.

         Otherwise, returns NULL.

         The caller must inspect the function return status to see whether
         the function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @todo KS: Add see macro
     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIString* (*getOwningEntity) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Get the `MessageID` attribute of a CMPIError object.

     CMPIErrorFT.getMessageID() returns a string which is the message ID.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `MessageID` attribute of the
         CMPIError object is non-NULL, returns a pointer to a
         CMPIString object, indicating the value of the `MessageID`
         attribute of the CMPIError object.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPIError
         object which will be released along with that object, or a new object
         created by the MB which will be released automatically by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         Otherwise, returns NULL.

         The caller must inspect the function return status to see whether the
         function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIString* (*getMessageID) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Get the `Message` attribute of a CMPIError object.

     CMPIErrorFT.getMessage() returns a string comnating an error message.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `Message` attribute of the CMPIError object
         is non-NULL, returns a pointer to a CMPIString object, indicating the
         value of the `Message` attribute of the CMPIError object.

         Otherwise,returns NULL.

         The caller must inspect the function return status to see whether
         the function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIString* (*getMessage) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Get the `PerceivedSeverity` attribute of a CMPIError object

     CMPIErrorFT.getPerceivedSeverity() returns the PerceivedSeverity
     attribute of a CMPIError object.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a @ref CMPIErrorSeverity enumeration
         value will be returned, indicating the value of the `PerceivedSeverity`
         attribute of the CMPIError object.

         If not successful, the returned value is undefined.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIErrorSeverity (*getPerceivedSeverity) (const CMPIError* er,
        CMPIStatus* rc);

    /**
     @brief Get the `ProbableCause` attribute of a CMPIError object.

     CMPIErrorFT.getProbableCause() returns the ProbableCause attribute
     of a CMPIError object.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a @ref CMPIErrorProbableCause enumeration
         value will be returned, indicating the value of the @p ProbableCause
         attribute of the CMPIError object.

         If not successful, the returned value is undefined.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIErrorProbableCause (*getProbableCause) (const CMPIError* er,
        CMPIStatus* rc);

    /**
     @brief Get the `ProbableCauseDescription` attribute of a CMPIError object.

     CMPIErrorFT.getProbableCauseDescription() returns a string which
     describes the probable cause.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `ProbableCauseDescription`
         attribute of the CMPIError object is non-NULL, returnsa pointer to a
         CMPIString object, indicating the value of the ProbableCauseDescription
         attribute of the CMPIError object.

         Otherwise, returns NULL.

         The caller must inspect the function return status to see whether
         the function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIString* (*getProbableCauseDescription) (const CMPIError* er,
        CMPIStatus* rc);

    /**
     @brief Get the `RecommendedActions` array attribute of a CMPIError object.

     CMPIErrorFT.getRecommendedActions() returns an array of strings which
     describes recomended actions of the CMPIError object.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `RecommendedActions` array
         attribute of the CMPIError object is non-NULL, returns a pointer to a
         CMPIArray object, containing CMPIString elements that represent the
         array elements of the `RecommendedActions` array attribute in the
         CMPIError object.

         Otherwise, returns NULL.

         The caller must inspect the function return status to see whether
         the function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIArray* (*getRecommendedActions) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Get the `ErrorSource` attribute of a CMPIError object.

     CMPIErrorFT.getErrorSource() returns a string which describes the
     Error source of the CMPIError object.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `ErrorSource` attribute of the
         CMPIError object is non-NULL, returns a pointer to a CMPIString object,
         indicating the value of the `ErrorSource` attribute of the
         CMPIError object. Otherwise, returns NULL.

         The caller must inspect the function return status to see whether
         the function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIString* (*getErrorSource) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Get the `ErrorSourceFormat` attribute of a CMPIError object.

     CMPIErrorFT.getErrorSourceFormat() returns a the format that the
     error src is in.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a @ref
         CMPIErrorSrcFormat enumeration, indicating the value of the
         `ErrorSourceFormat` attribute of the CMPIError object.

         If not successful, the returned value is undefined.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIErrorSrcFormat (*getErrorSourceFormat) (const CMPIError* er,
        CMPIStatus* rc);

    /**
     @brief Get the `OtherErrorSourceFormat` attribute of a CMPIError object.

     CMPIErrorFT.getOtherErrorSourceFormat() returns a string which
     describes the 'other' format; only available
     if the error source is OTHER.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `OtherErrorSource` attribute of
         the CMPIError object is non-NULL, returns a pointer to a
         CMPIString object, indicating the value of the
         `OtherErrorSourceFormat` attribute of the CMPIError object.
         Otherwise, returns NULL.

         The caller must inspect the function return status to see whether
         the function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIString* (*getOtherErrorSourceFormat) (const CMPIError* er,
        CMPIStatus* rc);

    /**
     @brief Get the `CIMStatusCode` attribute of a CMPIError object.

     CMPIErrorFT.getCIMStatusCode() gets the value of the
     `CIMStatusCode` attribute of a CMPIError object.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a @ref CMPIrc value indicating
         the value of the `CIMStatusCode` attribute of the CMPIError
         object. Please note that not all status codes apply to all
         situations.

         It is up to the MI to ensure the correct status code is set.

         If not successful, the returned value is undefined.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIrc (*getCIMStatusCode) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Get `CIMStatusCodeDescription` attribute of a CMPIError object.

     CMPIErrorFT.getCIMStatusCodeDescription() gets the
     value of the `CIMStatusCodeDescription` attribute of a CMPIError
     object.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `CIMStatusCodeDescription`
         attribute of the CMPIError object is non-NULL, returns a
         pointer to a CMPIString object, indicating the value of the
         CIMStatusCodeDescription attribute of the CMPIError object.

         Otherwise, returns NULL.

         The caller must inspect the function return status to see
         whether the function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIString* (*getCIMStatusCodeDescription) (const CMPIError* er,
        CMPIStatus* rc);

    /**
     @brief Get the `MessageArguments` array attribute of a CMPIError object.

     CMPIErrorFT.getMessageArguments() gets the value of
     the `MessageArguments` array attribute of a CMPIError object.

     @param er Points to the CMPIError object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful and the `MessageArguments` array attribute
         of the CMPIError object is non-NULL, returns a pointer to a
         CMPIArray object, containing CMPIString objects that
         represent the array elements of the MessageArguments array
         attribute of the CMPIError object. Otherwise, returns NULL.

         The caller must inspect the function return status to see whether the
         function failed.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIArray* (*getMessageArguments) (const CMPIError* er, CMPIStatus* rc);

    /**
     @brief Set the `ErrorType` attribute of a CMPIError object.

     CMPIErrorFT.setErrorType() sets the value of the
     `ErrorType` attribute of this CMPIError object.

     @param er Points to the CMPIError object for this function.
     @param et CMPIErrorType enumeration value specifying the new value for
         the `ErrorType` attribute. If the error message in the
         CMPIError object
         is defined in a DMTF message registry, @p et shall
         reflect the content of the `ERROR_TYPE` element defined for
         the message in the registry.
     @return CMPIStatus structure containing the function return status

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setErrorType) (const CMPIError* er, const CMPIErrorType et);

    /**
     @brief Set the `OtherErrorType` attribute of a CMPIError object.

     CMPIErrorFT.setOtherErrorType() sets the `OtherErrorType` attribute
     of this CMPIError object.

     @param er Points to the CMPIError object for this function.
     @param oet Points to a string specifying the new non-NULL
         value for the OtherErrorType attribute, or is NULL
         specifying that the attribute will be set to NULL. If the
         error message is defined in a DMTF message registry, the
         string value of @p oet shall be the content of
         the OTHER_ERROR_TYPE element defined for the message in the
         registry It is only valid when error type is "OTHER"
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setOtherErrorType) (const CMPIError* er, const char* oet);

    /**
     @brief Set the `ProbableCauseDescription` attribute of a CMPIError object.

     CMPIErrorFT.setProbableCauseDescription() sets the description of the
     probable cause.

     @param er Points to the CMPIError object for this function.
     @param pcd string specifying the new non-NULL value for the
         `ProbableCauseDescription` attribute, or is NULL specifying
         that the attribute will be set to NULL. If the error
         message is defined in a DMTF message registry, note that
         the string value of @p pcd is not defined in the
         message in the registry.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setProbableCauseDescription) (const CMPIError* er,
        const char* pcd);

    /**
     @brief Set the `RecommendedActions` array attribute of a CMPIError object.

     CMPIErrorFT.setRecommendedActions() sets the value
     of the `RecommendedActions` array attribute of a CMPIError
     object.

     For a description of the RecommendedActions attribute, see
     the description of the RecommendedActions property in the
     CIM_Error class in the CIM Schema.

     @param er Points to the CMPIError object for this function.
     @param ra pointer to a CMPIArray object specifying the new array value
         for the RecommendedActions array attribute. The CMPIArray object
         contains CMPIString objects or NULL values as array elements. @p ra
         may be NULL, specifying that the RecommendedActions array
         attribute will be set to NULL. If the error message is defined in a
         DMTF message registry, @p ra shall reflect the values
         defined in the RECOMMENDED_ACTION elements defined for the message
         in the registry, in the order defined there.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setRecommendedActions) (const CMPIError* er,
        const CMPIArray* ra);

    /**
     @brief Set the `ErrorSource` attribute of a CMPIError object.

     CMPIErrorFT.setErrorSource() sets the value of the ErrorSource
     attribute of a CMPIError object.

     For a description of the ErrorSource attribute, see the
     description of the ErrorSource property in the CIM_Error class
     in the CIM Schema

     @param er Points to the CMPIError object for this function.
     @param es string specifying the new non-NULL value for the ErrorSource
         attribute, or is NULL specifying that the attribute will be set to
         NULL. If the error message is defined in a DMTF message registry,
         the string value of @p es shall be the content of the
         ERROR_SOURCE element defined for the message in the registry.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setErrorSource) (const CMPIError* er, const char* es);

    /**
     @brief Set the `ErrorSourceFormat` attribute of a CMPIError object.

     CMPIErrorFT.setErrorSourceFormat() sets the source format of
     the error object. For a description of the ErrorSourceFormat
     attribute, see the description of the ErrorSourceFormat
     property in the CIM_Error class in the CIM Schema.

     @param er Points to the CMPIError object for this function.
     @param esf CMPIErrorSrcFormat enumeration value specifying the new value
         for the ErrorSourceFormat attribute. If the error message is defined
         in a DMTF message registry, the string value of @p esf shall
         be the content of the ERROR_SOURCE_FORMAT element defined for the
         message in the registry
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setErrorSourceFormat) (const CMPIError* er,
        const CMPIErrorSrcFormat esf);

    /**
     @brief Set the `OtherErrorSourceFormat` attribute of a CMPIError object

     CMPIErrorFT.setOtherErrorSourceFormat() specifies a string
     defining "Other" values for `ErrorSourceFormat`

     @param er Points to the CMPIError object for this function.
     @param oef Points to a string specifying the new non-NULL value for
         the `OtherErrorSourceFormat` attribute, or NULL specifying
         that the attribute will be set to NULL. If the error message is
         defined in a DMTF message registry, the string value of
         @p oef shall be the content of the
         OTHER_ERROR_SOURCE_FORMAT element defined for the message in the
         registry.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setOtherErrorSourceFormat) (const CMPIError* er,
        const char* oef);

    /**
     @brief Set the `CIMStatusCodeDescription` attribute of a CMPIError object

     CMPIErrorFT.setCIMStatusCodeDescription() sets the
     description of the status code. For a description of the
     `CIMStatusCodeDescription` attribute, see the description of the
     `CIMStatusCodeDescription` property in the `CIM_Error`
     class in the CIM Schema.

     @param er Points to the CMPIError object for this function.
     @param scd A Pointer to a string specifying the new non-NULL value
         for the `CIMStatusCodeDescription` attribute, or NULL specifying
         that the attribute will be set to NULL. If the error message is defined
         in a DMTF message registry, note that the string value of
         @p scd is not defined in the message in the registry.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setCIMStatusCodeDescription) (const CMPIError* er,
        const char* scd);

    /**
     @brief Set the `MessageArguments` array attribute of a CMPIError object.

     CMPIErrorFT.setMessageArguments() sets an array of strings
     for the dynamic content of the message. For a
     description of the `MessageArguments` attribute, see the
     description of the `MessageArguments` property in the
     `CIM_Error` class in the CIM Schema.

     @param er Points to the CMPIError object for this function.
     @param values CMPIArray object specifying the new array value
         for the `MessageArguments` array attribute. The CMPIArray
         object contains CMPIString objects or NULL values as array
         elements. @p values may be NULL, specifying that the
         `MessageArguments` array attribute will be set to NULL. If the
         error message is defined in a DMTF message registry, @p values
         shall reflect the values defined in the DYNAMIC_ELEMENT
         elements defined for the message in the registry, in the order
         defined there.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - One of the arguments is invalid.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.

     @required210 Support for this function is required since CMPI 2.1.0.
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. It will not be returned because the
         @ref CMPI_MB_Supports_Extended_Error "Extended Errors" capability
         will be available.
    */
    CMPIStatus (*setMessageArguments) (const CMPIError* er,
        const CMPIArray* values);

} CMPIErrorFT;

#endif /*CMPI_VER_200*/

/**
 * @}
 * @addtogroup edt-instance
 * @{
 */

/**
 * @brief CMPIInstance encapsulated data type object.
 */
typedef struct _CMPIInstance {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIInstanceFT* ft;

} CMPIInstance;

/**
 * @brief Function table of CMPIInstance encapsulated data type object.
 */
typedef struct _CMPIInstanceFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIInstance object.

     CMPIInstanceFT.release() releases a CMPIInstance object.
     This indicates to the MB that the object (including any objects it
     contains) will no longer be used by the MI. The MB may free (=reclaim)
     the memory associated with the object during the call to this function,
     or later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param inst Points to the CMPIInstance object to be released.
         That object shall have been created using CMPIInstanceFT.clone().
     @return CMPIStatus structure containing the function return status.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIInstance* inst);

    /**
     @brief Create an independent copy of a CMPIInstance object.

     CMPIInstanceFT.clone() creates an independent copy of this
     Instance object. The resulting
     object must be released explicitly.

     @param inst Points to the CMPIInstance object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return If successful, a pointer to the copied CMPIInstance object.

     The returned CMPIInstance object shall be explicitly released by the
     MI using CMPIInstanceFT.release().

     If not successful, NULL will be returned.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle is invalid.

     @see CMClone()
    */
    CMPIInstance* (*clone) (const CMPIInstance* inst, CMPIStatus* rc);

    /**
     @brief Get a property in a CMPIInstance object by name.

     CMPIInstanceFT.getProperty() gets a named property value from
     an instance.

     @param inst Points to the CMPIInstance object for this function.
     @param name Points to a string containing the property name.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPIData structure containing the
         specified property will be returned.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Property not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle is invalid.

     @see CMGetProperty()
    */
    CMPIData (*getProperty) (const CMPIInstance* inst, const char* name,
        CMPIStatus* rc);

    /**
     @brief Get a property in a CMPIInstance object by index.

     CMPIInstanceFT.getPropertyAt() gets a property at @p index
     in a CMPIInstance object .

     @param inst Points to the CMPIInstance object for this function.
     @param index Zero-based index number of the property in the internal
         data array.
     @param [out] name If not NULL, points to a CMPIString pointer
         that upon success is updated to point to a CMPIString object
         containing the property name. The returned CMPIString object
         shall not be explicitly released by the MI, because it may be an
         internal object of the CMPIString object which will be
         released along with that object, or a new object created by
         the MB which will be released automatically by the MB.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPIData structure
         containing the specified property.

         If not successful, CMPIData state will have the @ref CMPI_badValue
         is flag set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Property not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle is invalid.

     @see CMGetPropertyAt()
    */
    CMPIData (*getPropertyAt) (const CMPIInstance* inst, CMPICount index,
        CMPIString** name, CMPIStatus* rc);

    /**
     @brief Get the number of properties in a CMPIInstance  object.

     CMPIInstanceFT.getPropertyCount() gets the number of properties
     contained a CMPIInstance.

     @param inst Points to the CMPIInstance object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPICount value indicating
         the number of properties in the instance.

         If not successful, 0 returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle is invalid.

     @see CMGetPropertyCount()
    */
    CMPICount (*getPropertyCount) (const CMPIInstance* inst, CMPIStatus* rc);

    /**
     @brief Set a property value in a CMPIInstance object by name.

     CMPIInstanceFT.setProperty() adds or replace the named Property in
     the instance defined by
     @p inst. If the property is a key property, the function may
     or may not in addition add or update the key binding in the object
     path of the instance. In order for MIs not to be dependent on this
     behavior, MIs should set key property values in instances and key
     binding values in object paths separately. Key binding values can
     be set during CMPIBrokerEncFT.newInstance() and by using
     CMPIInstanceFT.setObjectPath(). The MI shall specify
     consistent values for key bindings and key properties.

     @param inst Points to the CMPIInstance object for this function.
     @param name Points to a string containing the property name.
     @param value CMPIValue structure containing the non-NULL
         value to be assigned to the property, or NULL to specify that
         NULL is to be assigned.
     @param type CMPIType value specifying the type of the value to
         be assigned to the property. All types of CIM values are supported.
         If the value of @p type is @ref CMPI_chars or
         @ref CMPI_charsA, the C-language string to which the chars member
         of @p value points is copied by this function and the
         original string memory may be freed by the MI right after
         this function returns.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_TYPE_MISMATCH` - @p type does not correspond
         to the class-defined type.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - @p name is not a valid
         property name.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.

     @see CMSetProperty()
    */
    CMPIStatus (*setProperty) (const CMPIInstance* inst, const char* name,
        const CMPIValue* value, CMPIType type);

    /**
     @brief Get a CMPIObjectPath object from a CMPIInstance object.

     CMPIInstanceFT.getObjectPath() generates a CMPIObjectPath object from
     the namespace, class name, and key properties of a CMPIInstance
     object.

     @param inst Points to the CMPIInstance object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a CMPIObjectPath object
         representing the instance path of the CMPIInstance.

         The returned CMPIObjectPath object shall not be explicitly
         released by the MI, because it may be an internal object of the
         CMPIInstance object which will be released along with that object,
         or a new object created by the MB which will be released automatically
         by the MB.

         If not successful, NULL will be returned
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle is invalid.

     @see CMGetObjectPath()
    */
    CMPIObjectPath* (*getObjectPath) (const CMPIInstance* inst,
        CMPIStatus* rc);

    /**
     @brief Attach a property filter to a CMPIInstance object.

     CMPIInstanceFT.setPropertyFilter() attaches a property filter to a
     CMPIInstance object, replacing any previous property filter settings for
     this object.
     By calling this function, the MI delegates property list filtering
     to the MB for this CMPIInstance object, for all of its properties
     including those that had already been set before the call to
     `setPropertyFilter()`.

     Filtering directs CMPI to ignore any setProperty operations for this
     instance for any properties not in this list.

     This function shall be supported by the MB if the
     @ref CMPI_MB_PropertyFiltering "Property Filtering" capability
     is available; otherwise, it shall not be supported.

     @param inst Points to the CMPIInstance object for this function.
     @param propertyList If not NULL, the members of the array define one
         or more Property names to be accepted by setProperty operations. A NULL
         value effectively means that all properties will be accepted.
         A pointer to an empty array means that no properties will be accepted.
     @param keys Deprecated, ignored by MB, maintained here for compatibility.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - @p keyList is missing.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle is invalid.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @capfiltering This function is part of the Property Filtering
         MB capability.

     @see CMSetPropertyFilter()
    */
    CMPIStatus (*setPropertyFilter) (const CMPIInstance* inst,
        const char** propertyList, const char** keys);

    /**
     @brief Set the instance path component of a CMPIInstance object.

     CMPIInstanceFT.setObjectPath() sets the CMPIObjectPath component
     in an instance.

     The function may or may not in addition update the key property
     values in the instance to the values of the key bindings in the object
     path. In order for MIs not to be dependent on this behavior, MIs should
     set key property values in instances and key binding values in
     object paths separately. Property values can be set by using
     CMPIInstanceFT.setProperty() or CMPIInstanceFT.setPropertyWithOrigin().
     The MI shall specify consistent values for key bindings and key properties.

     @param inst Points to the CMPIInstance object for this function.
     @param op Points to a CMPIObjectPath structure. This objectpath
         shall contain a non-NULL namespace, non-NULL classname, as well as all
         keys for the specified instance. The object path may specify a non-NULL
         host for the instance (this is used for instances returned by
         cross-host associations).
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle or
         @p op handle is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - Object path components specified
         in @p op are invalid.

     @see CMSetObjectPath()
    */
    CMPIStatus (*setObjectPath) (const CMPIInstance* inst,
        const CMPIObjectPath* op);

#ifdef CMPI_VER_200

    /**
     @brief Add or replace a property value in a CMPIInstance object by name.

     CMPIInstanceFT.setPropertyWithOrigin() adds or replaces a Property value
     and origin in a CMPIInstance.

     If the property is a key property, the function may or may not in addition
     add or update the key binding in the object path of the instance. In
     order for MIs not to be dependent on this behavior, MIs should set
     key property values in instances and key binding values in object
     paths separately. Key binding values can be set during
     CMPIBrokerEncFT.newInstance()" and by using
     CMPIInstanceFT.setObjectPath(). The MI shall specify consistent
     values for key bindings and key properties.

     @param inst Points to the CMPIInstance object for this function.
     @param name CMPIString containing the property name.
     @param value Points to a CMPIValue structure containing the value
         to be assigned to the property.
     @param type CMPIType structure defining the type of the value.
     @param origin the name of the class in which this property was
         originally defined. If NULL, then no origin is attached to  the
         property.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_TYPE_MISMATCH` - @p type does not
         correspond to class-defined type.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p inst handle is invalid.

     @see CMSetPropertyWithOrigin()
     @added200 Added in CMPI 2.0.0.
    */
    CMPIStatus (*setPropertyWithOrigin) (const CMPIInstance* inst,
        const char* name, const CMPIValue* value, const CMPIType type,
        const char* origin);

#endif /*CMPI_VER_200*/

} CMPIInstanceFT;

/**
 * @}
 * @addtogroup edt-objectpath
 * @{
 */

/**
 * @brief CMPIObjectPath encapsulated data type object.
 */
typedef struct _CMPIObjectPath {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIObjectPathFT* ft;

} CMPIObjectPath;

/**
 * @brief Function table of CMPIObjectPath encapsulated data type object.
 */
typedef struct _CMPIObjectPathFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIObjectPath object.

     CMPIObjectPathFT.release() releases a CMPIObjectPath object.

     The CMPIObjectPath object will not be used any further and
     may be freed by CMPI run time system.

     @param op Points to the CMPIObjectPath object to be released.
         That object shall have been created using CMPIObjectPathFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIObjectPath* op);

    /**
     @brief Create an independent copy of a CMPIObjectPath object.

     CMPIObjectPathFT.clone() creates an independent copy of this
     CMPIObjectPath object. The resulting
     object must be released explicitly.

     @param op Points to the CMPIObjectPath object to be cloned.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the copied CMPIObjectPath.

         The returned CMPIObjectPath object shall be explicitly released by the
         MI using CMPIObjectPathFT.release().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMClone()
    */
    CMPIObjectPath* (*clone) (const CMPIObjectPath* op, CMPIStatus* rc);

    /**
     @brief Add the namespace component to a `CIMObjectPath` object.

     CMPIObjectPathFT.setNameSpace() sets or replaces the namespace component
     in the CMPIObjectPath object defined by @p op.

     @param op Points to the CMPIObjectPath object for this function.
     @param ns CMPI String containing the namespace to add.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMSetNameSpace()
    */
    CMPIStatus (*setNameSpace) (const CMPIObjectPath* op, const char* ns);

    /**
     @brief Get the namespace component from a CMPIObjectPath object.

     CMPIObjectPathFT.getNameSpace() gets the namespace component from a
     CMPIObjectPath object.

     @param op Points to the CMPIObjectPath object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to a CMPIString object
         containing the namespace component of the object path will
         be returned.

         The returned CMPIString object shall not be
         explicitly released by the MI, because it may be an
         internal object of the CMPIObjectPath object which will be
         released along with that object, or a new object created by
         the MB which will be released automatically by the MB.

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMGetNameSpace()
    */
    CMPIString* (*getNameSpace) (const CMPIObjectPath* op, CMPIStatus* rc);

    /**
     @brief Set the host name component in a CMPIObjectPath object.

     CMPIObjectPathFT.setHostname() sets or replaces the host name component
     in @p op a CMPIObjectPath object with argument @p hn.

     @param op Points to the CMPIObjectPath object for this function.
     @param hn Points to a CMPIString containing the host name.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMSetHostname()
    */
    CMPIStatus (*setHostname) (const CMPIObjectPath* op, const char* hn);

    /**
     @brief Get the host name component in a CMPIObjectPath object.

     CMPIObjectPathFT.getHostname() gets the host name component from a
     CMPIObjectPath object.

     @param op Points to the CMPIObjectPath object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a CMPIString object
         containing the host name component of the object path.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPIObjectPath
         object which will be released along with that object, or a new object
         created by the MB which will be released automatically by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMGetHostname()
    */
    CMPIString* (*getHostname) (const CMPIObjectPath* op, CMPIStatus* rc);

    /**
     @brief Set class name component in a CMPIObjectPath object.

     Set/replace the class name component in the CMPIObjectPath object.

     @param op Points to the CMPIObjectPath object for this function.
     @param cn specifies the new class name.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMGetClassName()
    */
    CMPIStatus (*setClassName) (const CMPIObjectPath* op, const char* cn);

    /**
     @brief Get class name component in a `CIMObjectPath` object.

     CMPIObjectPathFT.getClassName() gets the classname component in a
     CMPIObjectPath object.

     @param op Points to the CMPIObjectPath object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a CMPIString object
         containing the class name component of the object path.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the
         CMPIObjectPath object which will be released along with
         that object, or a new object created by the MB which will be
         released automatically by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMGetClassName()
    */
    CMPIString* (*getClassName) (const CMPIObjectPath* op, CMPIStatus* rc);

    /**
     @brief Add or replace a key binding in a CMPIObjectPath object.

     CMPIObjectPathFT.addKey() adds or replaces a key binding in a
     CMPIObjectPath object.

     @param op Points to the CMPIObjectPath object for this function.
     @param name Points to string containing key name.
     @param value CMPIValue containing the value to be assigned to the
         key binding Key binding values must NOT be NULL.
     @param type Value type to be assigned to the key binding. All types of CIM
         values are valid for keys are supported. If the value of @p type
         is @ref CMPI_chars or @ref CMPI_charsA, the C-language string
         to which the chars member of @p value points is
         copied by this function and the original string memory
         may be freed by the MI right after this function returns
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p key or
         @p value argument is invalid.

     @see CMAddKey()
    */
    CMPIStatus (*addKey) (const CMPIObjectPath* op, const char* name,
        const CMPIValue* value, const CMPIType type);

    /**
     @brief Get a key binding in a CMPIObjectPath object by name.

     CMPIObjectPathFT.getKey() gets a key binding in a
     CMPIObjectPath object by name.

     @param op Points to the CMPIObjectPath object for this function.
     @param name Name of the key binding.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         A CMPIData structure.

         If successful, the returned CMPIData structure contains the value of
         the key binding.

         The MB will attempt to set the type in the returned CMPIData structure
         to the precise CIM type, if available. Versions of the CIM-XML protocol
         before @ref ref-dmtf-dsp0200 "DSP0200" Version 1.4 did not mandate the
         presence of the precise CIM type. In those versions, the precise CIM
         type was only recommended to be present. If the precise CIM type is not
         available to the MB, it will use the following more general types in
         the returned CMPIData structure:

         <pre>
         \#define CMPI_keyInteger   (CMPI_sint64)
         \#define CMPI_keyString    (CMPI_string)
         \#define CMPI_keyBoolean   (CMPI_boolean)
         \#define CMPI_keyRef       (CMPI_ref)</pre>

         In addition, the @ref CMPI_keyValue flag will be set in CMPIData.state
         to indicate that the value is a key binding.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Key not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMGetKey()
    */
    CMPIData (*getKey) (const CMPIObjectPath* op, const char* name,
        CMPIStatus* rc);

    /**
     @brief Get a key binding in a CMPIObjectPath object by index.

     CMPIObjectPathFT.getKeyAt() gets a key binding in a
     CMPIObjectPath object by index.

     @param op Points to the CMPIObjectPath object for this function.
     @param index Zero-based position of the key binding within the internal
         data array.
     @param [out] name Points to a CMPIString pointer that upon success
         will have been updated to point to a CMPIString object specifying the
         name of the key binding. That CMPIString object shall not be explicitly
         released by the MI, because it may be an internal object of the
         CMPIObjectPath object which will be released along with that object, or
         a new object created by the MB which will be released automatically by
         the MB.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         A CMPIData structure.

         If successful, the returned CMPIData structure will contain the value
         of the key binding.

         The MB will attempt to set the type in the returned CMPIData structure
         to the precise CIM type, if available. Versions of the CIM-XML protocol
         before @ref ref-dmtf-dsp0200 "DSP0200" Version 1.4 did not mandate the
         presence of the precise
         CIM type. In those versions, the precise CIM type was only recommended
         to be present. If the precise CIM type is not available to the MB, it
         will use the following more general types in the returned CMPIData
         structure:

         <pre>
         \#define CMPI_keyInteger   (CMPI_sint64)
         \#define CMPI_keyString    (CMPI_string)
         \#define CMPI_keyBoolean   (CMPI_boolean)
         \#define CMPI_keyRef       (CMPI_ref)</pre>

         In addition, the @ref CMPI_keyValue flag will be set in CMPIData.state
         to indicate that the value is a key binding.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Key not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMGetKeyAt()
    */
    CMPIData (*getKeyAt) (const CMPIObjectPath* op, CMPICount index,
            CMPIString** name, CMPIStatus* rc);

    /**
     @brief Get the number of key bindings in a CMPIObjectPath object.

     CMPIObjectPathFT.getKeyCount() gets the number of key bindings contained
         in this CMPIObjectPath.

     @param op Points to the CMPIObjectPath object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPICount value indicating
         the number of key bindings will be returned. If the
         CMPIObjectPath object does not have a key component, the
         function will succeed and return 0.

         If not successful, 0 will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.

     @see CMGetKeyCount()
    */
    CMPICount (*getKeyCount) (const CMPIObjectPath* op, CMPIStatus* rc);

    /**
     @brief Set/replace the namespace and class name components in a
     CMPIObjectPath object from another CMPIObjectPath object

     CMPIObjectPathFT.setNameSpaceFromObjectPath() sets or replace namespace
     and classname components in CMPIObjectPath
     @p op from CMPIObjectPath @p src.

     @param op Points to the CMPIObjectPath object for this function.
     @param src a CMPIObjectPath object used as the source for the new
         namespace and class name components.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - @p src is invalid.

     @see CMSetNameSpaceFromObjectPath()
    */
    CMPIStatus (*setNameSpaceFromObjectPath) (const CMPIObjectPath* op,
        const CMPIObjectPath* src);

    /**
     @brief Set host name, namespace, and class name components
     in a CMPIObjectPath object from another CMPIObjectPath
     object.

     CMPIObjectPathFT.setHostAndNameSpaceFromObjectPath() sets/replaces
     hostname, namespace and classname components in the
     CMPIObjectPath @p op from the CMPIObjectPath @p src.

     @param op Points to the CMPIObjectPath object for this function.
     @param src CMPIObjectPath object used as the source for the new host name,
         namespace, and class name components.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - @p src is invalid.

     @see CMSetHostAndNameSpaceFromObjectPath()
    */
    CMPIStatus (*setHostAndNameSpaceFromObjectPath) (const CMPIObjectPath* op,
        const CMPIObjectPath* src);

    /**
     @brief Get a class qualifier.

     CMPIObjectPathFT.getClassQualifier() gets a class qualifier in the class
     identified by the CMPIObjectPath @p op argument.

     @param op Points to a CMPIObjectPath object that references the class
         and that shall contain the namespace and class components.
         The hostname and key components, if present, will be ignored by the MB.
     @param qName Qualifier name.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIData structure
         containing the specified qualifier.

         If not successful, CMPIData.state @ref CMPI_badValue flag set
         to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace implied by
         @p op is invalid.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p op does not exist.
     @li `CMPI_RC_ERR_NOT_FOUND` - The qualifier specified in
         @p qName is invalid for classes.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @capqualifiers This function is part of the Basic Qualifier MB capability.

     @see CMGetClassQualifier()
    */
    CMPIData (*getClassQualifier) (const CMPIObjectPath* op,
        const char* qName, CMPIStatus* rc);

    /**
     @brief Get a property qualifier.

     CMPIObjectPathFT.getPropertyQualifier() function gets a property
     qualifier in the class identified by @p op.

     @param op Points to a CMPIObjectPath object that references the
         class and that shall contain the namespace and class components.
         The hostname and key components, if present, will be ignored by the MB.
     @param pName Property name.
     @param qName Points to a string specifying the qualifier name.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIData structure
         containing the specified qualifier will be returned.

         If not successful, returns CMPIData.state with @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace implied by
         @p op is invalid.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p op does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The property (or reference)
         specified in @p pName is not exposed by the class
         specified in @p op.
     @li `CMPI_RC_ERR_NOT_FOUND` - The qualifier specified in the
         @p qNamet argumen is invalid for classes.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @capqualifiers This function is part of the Basic Qualifier MB capability.

     @see CMGetPropertyQualifier()
    */
    CMPIData (*getPropertyQualifier) (const CMPIObjectPath* op,
        const char* pName, const char* qName, CMPIStatus* rc);

    /**
     @brief Get a method qualifier.

     CMPIObjectPathFT.getMethodQualifier() gets method qualifier value.

     @param op Points to a CMPIObjectPath object that references the class
         and that shall contain the namespace and class components. The
         hostname and key components, if present, will be ignored by the MB.
     @param mName Method name.
     @param qName Qualifier name.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPIData structure
         containing the specified qualifier will be returned.

         If not successful, CMPIData.state will have the @ref CMPI_badValue
         flag set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace implied by
         @p op is invalid.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p op does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The property (or reference)
         specified in @p pName is not exposed by the class
         specified in @p op.
     @li `CMPI_RC_ERR_NOT_FOUND` - The qualifier specified in
         @p qName is invalid for classes.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @capqualifiers This function is part of the Basic Qualifier MB capability.

     @see CMGetMethodQualifier()
    */
    CMPIData (*getMethodQualifier) (const CMPIObjectPath* op,
        const char* methodName, const char* qName, CMPIStatus* rc);

    /**
     @brief Get a parameter qualifier.

     CMPIObjectPathFT.getParameterQualifier() gets a parameter qualifier in
     the class identified by this object path.

     @param op Points to a CMPIObjectPath object that references the
         class and that shall contain the namespace and class components.
         The hostname and key components, if present, will be ignored by
         the MB.
     @param mName Points to a string specifying the method name.
     @param pName Points to a string specifying the parameter name.
     @param qName Points to a string specifying the qualifier name.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPIData structure containing the specified qualifier
         will be returned.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p op handle is invalid.
     @li `CMPI_RC_ERR_INVALID_NAMESPACE` - The namespace implied by
         @p op is invalid.
     @li `CMPI_RC_ERR_INVALID_CLASS` - The class specified in
         @p op does not exist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The method
         specified in @p mName is not exposed by the class
         specified in @p op, or it does not have a
         parameter with the name specified in @p pName.
     @li `CMPI_RC_ERR_NOT_FOUND` - The qualifier specified in
         @p qName is invalid for classes.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @capqualifiers This function is part of the Basic Qualifier MB capability.

     @see CMGetParameterQualifier()
    */
    CMPIData (*getParameterQualifier) (const CMPIObjectPath* op,
        const char* mName, const char* pName, const char* qName,
        CMPIStatus* rc);

    /**
     @brief Convert a CMPIObjectPath object into a string format.

     CMPIObjectPathFT.toString() generates a well formed
     implementation-specific string representation of this CMPIObjectPath.

     @param op Points to the CMPIObjectPath object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         CMPIString object containing the string representation of
         the object path.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPIObjectPath
         object which will be released along with that object, or a
         new object created by the MB which will be released automatically
         by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx handle is invalid.

     @todo KS: Add see macro
    */
    CMPIString* (*toString) (const CMPIObjectPath* op, CMPIStatus* rc);

} CMPIObjectPathFT;

/**
 * @}
 * @addtogroup qualifier-services
 * @{
 *   The qualifier services are the following member functions from the
 *   CMPIObjectPath encapsulated data type object:
 *
 *   @li CMPIObjectPathFT.getClassQualifier()
 *   @li CMPIObjectPathFT.getPropertyQualifier()
 *   @li CMPIObjectPathFT.getMethodQualifier()
 *   @li CMPIObjectPathFT.getParameterQualifier()
 * @}
 * @addtogroup edt-selectexp
 * @{
 */

/**
 * @brief CMPISelectExp encapsulated data type object.
 *
 * @capquerynorm This encapsulated data type is part of the Query Normalization
 *     MB capability.
 */
typedef struct _CMPISelectExp {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPISelectExpFT* ft;

} CMPISelectExp;

/**
 * @brief Function table of CMPISelectExp encapsulated data type object.
 */
typedef struct _CMPISelectExpFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPISelectExp object.

     CMPISelectExpFT.release() releases a CMPISelectExp object. This
     indicates to the MB that the object (including any objects it
     contains) will no longer be used by the MI. The MB may free (=reclaim)
     the memory associated with the object during the call to this
     function, or later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param se Points to the CMPISelectExp object to be released.
         That object shall have been created using CMPISelectExpFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p se handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPISelectExp* se);

    /**
     @brief Create an independent copy of a CMPISelectExp object.

     CMPISelectExpFT.clone() creates an independent copy of this
     CMPISelectExp object. The resulting object must be released explicitly.

     @param se Points to the CMPISelectExp object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the copied
         CMPISelectExp object will be returned.

         The returned CMPISelectExp object shall be explicitly released
         by the MI using CMPISelectExpFT.release().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p se handle is invalid.

     @see CMClone()
    */
    CMPISelectExp* (*clone) (const CMPISelectExp* se, CMPIStatus* rc);

    /**
     @brief Test whether an instance matches the select expression in a
         CMPISelectExp object.

     CMPISelectExpFT.evaluate() evaluates the instance @p inst using this
     select expression.

     @param se Points to the CMPISelectExp object for this function.
     @param inst Instance to be evaluated.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returnsCMPIBoolean value
         indicating the test result as follows:
         @li True indicates that the instance matches the select
         expression;
         @li False indicates that this is not the case.

         If not successful, False will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p se handle is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - @p inst is invalid.

     @see CMEvaluateSelExp()
    */
    CMPIBoolean (*evaluate) (const CMPISelectExp* se, const CMPIInstance* inst,
        CMPIStatus* rc);

    /**
     @brief Get the select expression in a CMPISelectExp object as a string.

     CMPISelectExpFT.getString() returns the select expression in
     string format.

     @param se Points to the CMPISelectExp object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         CMPIString object cointaining the select expression in
         string format.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPISelectExp
         object which will be released along with that object, or a new
         object created by the MB which will be released automatically by the
         MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p se handle is invalid.

     @see CMGetSelExpString()
    */
    CMPIString* (*getString) (const CMPISelectExp* se, CMPIStatus* rc);

    /**
     @brief Get the select expression in a CMPISelectExp object
         as a disjunction of conjunctions.

     CMPISelectExpFT.getDOC() gets the select expression as a
     disjunction of conjunctions. This function transforms the WHERE
     clause of the select expression into a canonical disjunction of
     onjunctions (DOC) form (OR?ing of AND?ed comparison expressions).
     This enables handling of the expression in the WHERE clause more
     easily than using a tree form.

     @param se Points to the CMPISelectExp object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         CMPISelectCond object containing the transformed select
         expression.

         The returned CMPISelectCond object shall not be explicitly released
         by the MI, because it may be an internal object of the
         CMPISelectExp object which will be released along with that
         object, or a new object created by the MB which will be
         released automatically by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p se handle is invalid.

     @see CMGetDOC()
    */
    CMPISelectCond* (*getDOC) (const CMPISelectExp* se, CMPIStatus* rc);

    /**
     @brief Get the select expression in a CMPISelectExp object as
         a conjunction of disjunctions.

     CMPISelectExpFT.getCOD() returns the select expression as
     conjunction of disjunctions.

     @param se Points to the CMPISelectExp object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         CMPISelectCond object containing the transformed select
         expression.

         The returned CMPISelectCond object shall not be explicitly released
         by the MI, because it may be an internal object of the
         CMPISelectExp object which will be released along with that
         object, or a new object created by the MB which will be
         released automatically by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p se handle is invalid.

     @see CMGetCOD()
    */
    CMPISelectCond* (*getCOD) (const CMPISelectExp* se, CMPIStatus* rc);

    /**
     @brief Test whether the properties returned by an accessor
        function match the select expression in a CMPISelectExp object.

     CMPISelectExpFT.evaluateUsingAccessor() tests whether the properties
     returned by an accessor
     function match the select expression in a CMPISelectExp object.
     This function is a variation of CMPISelectExpFT.evaluate(). It enables
     evaluation without the need to create a CMPIInstance object

     @param se Points to the CMPISelectExp object for this function.
     @param accessor Address of data accessor routine.
     @param parm Data accessor routine parameter.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIBoolean value
         indicating the test result will be returned, as follows:
         True indicates that the properties returned by the accessor
         function match the select expression; False indicates that
         this is not the case.

         If not successful, False will be returned
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p se handle is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - The @p accessorFnc handle is
         invalid.

     @see CMEvaluateSelExpUsingAccessor()
    */
    CMPIBoolean (*evaluateUsingAccessor) (const CMPISelectExp* se,
        CMPIAccessor* accessor, void* parm, CMPIStatus* rc);

} CMPISelectExpFT;

/**
 * @}
 * @addtogroup edt-selectcond
 * @{
 */

/**
 * @brief CMPISelectCond encapsulated data type object.
 *
 * @capquerynorm This encapsulated data type is part of the Query Normalization
 *     MB capability.
 */
typedef struct _CMPISelectCond {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPISelectCondFT* ft;

} CMPISelectCond;

/**
 * @brief Function table of CMPISelectCond encapsulated data type object.
 */
typedef struct _CMPISelectCondFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPISelectCond object.

     CMPISelectCondFT.release() releases a CMPISelectCond object. This
     indicates to the MB that the object (including any objects it contains)
     will no longer be used by the MI. The MB may free (=reclaim) the
     memory associated with the object during the call to this function,
     or later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param sc Points to the CMPISelectCond object to be released.
         That object shall have been created using CMPISelectCondFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p sc handle is invalid.

     @see CMRelease()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPIStatus (*release) (CMPISelectCond* sc);

    /**
     @brief Create an independent copy of a CMPISelectCond object.

     CMPISelectExpFT.clone() creates an independent copy of this SelectCond
     object. The resulting object must be released explicitly.

     @param sc Points to the CMPISelectCond object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the
         copied CMPISelectExp object.

         The returned CMPISelectExp object shall be explicitly released by
         the MI using CMPISelectExpFT.release().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p sc handle is invalid.

     @see CMClone()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPISelectCond* (*clone) (const CMPISelectCond* sc, CMPIStatus* rc);

    /**
     @brief Get the number and type of subconditions in a CMPISelectCond object.

     CMPISelectCondFT.getCountAndType() returns the number of subconditions
     that are part of this SelectCond.
     Optionally, the SelectCond type (COD or DOC) will be returned.

     @param sc Points to the CMPISelectCond object for this function.
     @param [out] type If not NULL, points to an integer that upon success
         is updated with the subcondition type. A value of 0 indicates a
         DOC type, and a value of 1 indicates a COD type. If type is NULL,
         no type information is returned.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPICount value
         indicating the number of subconditions.

         If not successful, returns 0.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p sc handle is invalid.

     @see CMGetSubCondCountAndType()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPICount (*getCountAndType) (const CMPISelectCond* sc, int* type,
            CMPIStatus* rc);

    /**
     @brief Get a subcondition in a CMPISelectCond object by index.

     CMPISelectCondFT.getSubCondAt() gets the subcondition in a
     CMPISelectCond object, by its index in the internal data array

     @param sc Points to the CMPISelectCond object for this function.
     @param index Specifies the zero-based position of the subcondition in
         the internal data array.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the
         specified CMPISubCond object will be returned.

         The returned CMPISubCond object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPISelectCond
         object which will be released along with that object, or a new object
         created by the MB which will be released automatically by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
         @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - @p index value out of bounds.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p sc handle is invalid.

     @see CMGetSubCondAt()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPISubCond* (*getSubCondAt) (const CMPISelectCond* sc, CMPICount index,
        CMPIStatus* rc);

} CMPISelectCondFT;

/**
 * @}
 * @addtogroup edt-subcond
 * @{
 */

/**
 * @brief CMPISubCond encapsulated data type object.
 *
 * @capquerynorm This encapsulated data type is part of the Query Normalization
 *     MB capability.
 */
typedef struct _CMPISubCond {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPISubCondFT* ft;

} CMPISubCond;

/**
 * @brief Function table of CMPISubCond encapsulated data type object.
 */
typedef struct _CMPISubCondFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPISubCond object.

     CMPISubCondFT.release() releases argument @p sc a CMPISubCond
     object.

     This indicates to the MB that the object (including any
     objects it contains) will no longer be used by the MI. The
     MB may free (=reclaim) the memory associated with the
     object during the call to this function, or later during
     some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param sc Points to the CMPISubCond object to be released.
         That object shall have been created using CMPISubCondFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p sc handle.

     @see CMRelease()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPIStatus (*release) (CMPISubCond* sc);

    /**
     @brief Create an independent copy of a CMPISubCond object.

     CMPISubCondFT.clone() creates an independent copy of a  @p sc
     CMPISubCond object.

     @param sc Points to the CMPISubCond object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPICount value
         indicating the number of subconditions.

         If not successful, returns 0.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p sc handle.

     @see CMClone()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
     */
    CMPISubCond* (*clone) (const CMPISubCond* sc, CMPIStatus* rc);

    /**
     @brief Get the number of predicates in a CMPISubCond object.

     CMPISubCondFT.getCount() gets the number of predicates in @p sc
     CMPISubCond object.

     @param sc Points to the CMPISubCond object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPICount value
         indicating the number of predicates in the CMPISubCond
         object.

         If not successful, returns 0.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p sc handle.

     @see CMGetPredicateCount()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPICount (*getCount) (const CMPISubCond* sc, CMPIStatus* rc);

    /**
     @brief Get a predicate in a CMPISubCond object by index.

     CMPISubCondFT.getPredicatAt() gets a predicate in a CMPISubCond
     object, by its index in the internal data array.

     @param sc Points to the CMPISubCond object for this function.
     @param index Specifies the zero-based index of the predicate in the
         internal data array.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         CMPIPredicate object containing the specified predicate.

         The returned CMPIPredicate object shall not be explicitly
         released by the MI, because it may be an internal object of
         the CMPISubCond object which will be released along with that
         object, or a new object created by the MB which will be released
         automatically by the MB.

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - @p index value out of bounds.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p sc handle.

     @see CMGetPredicateAt()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPIPredicate* (*getPredicateAt) (const CMPISubCond* sc, CMPICount index,
        CMPIStatus* rc);

    /**
     @brief Get a predicate in a CMPISubCond object by name.

     CMPISubCondFT.getPredicate() gets a predicate in a CMPISubCond
      object, by its @p name argument.

     @param sc Points to the CMPISubCond object for this function.
     @param name specifies the predicate name. The name is the left-hand side
         of the predicate.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         CMPIPredicate object containing the specified predicate.

         The returned CMPIPredicate object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPISubCond
         object which will be released along with that object, or a new object
         created by the MB which will be released automatically by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - @p index value out of bounds.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p sc handle.

     @see CMGetPredicate()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPIPredicate* (*getPredicate) (const CMPISubCond* sc, const char* name,
        CMPIStatus* rc);

} CMPISubCondFT;

/**
 * @}
 * @addtogroup edt-predicate
 * @{
 */

/**
 * @brief CMPIPredicate encapsulated data type object.
 *
 * @capquerynorm This encapsulated data type is part of the Query Normalization
 *     MB capability.
 */
typedef struct _CMPIPredicate {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIPredicateFT* ft;

} CMPIPredicate;

/**
 * @brief Function table of CMPIPredicate encapsulated data type object.
 */
typedef struct _CMPIPredicateFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPPredicate object.

     CMPIPredicateFT.release() releases a CMPIPredicate object. This
     indicates to the MB that the object (including any objects it contains)
     will no longer be used by the MI. The MB may free (=reclaim) the
     memory associated with the object during the call to this function,
     or later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param pr Points to the CMPIPredicate object to be released.
         That object shall have been created using CMPIPredicateFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p pr handle is invalid.

     @see CMRelease()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPIStatus (*release) (CMPIPredicate* pr);

    /**
     @brief Create an independent copy of a CMPIPredicate object.

     CMPIPredicateFT.clone() creates an independent copy of a
     CMPIPredicate object.

     @param pr Points to the CMPIPredicate object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the copied
         CMPIPredicate object will be returned.

         The returned CMPIPredicate object shall be explicitly released by the
         MI using CMPIPredicateFT.release().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p pr handle is invalid.

     @see CMClone()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPIPredicate* (*clone) (const CMPIPredicate* pr, CMPIStatus* rc);

    /**
     @brief Get the predicate components of a CMPIPredicate object.

     CMPIPredicateFT.getData() gets the predicate components of a
     CMPIPredicate object.

     The CMPIString objects returned by lhs and rhs shall not be explicitly
     released by the MI, because they may be internal objects of the
     CMPIContext object which will be released along with that object, or new
     objects created by the MB which will be automatically released by the
     MB
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param pr Points to the CMPIPredicate object for this function.
     @param [out] type If not NULL, points to a CMPIType structure that upon
         success will have been updated with the data type of the predicate.
     @param [out] prop If not NULL, points to a @ref CMPIPredOp object that upon
         success will have been updated with the predicate operation.
     @param [out] lhs if not NULL, points to a pointer to a CMPIString object
         that upon success will have been updated with the address of a
         CMPIString object representing the left-hand side of the predicate.
     @param [out] rhs , if not NULL, points to a pointer to a CMPIString object
         that upon success will have been updated with the address of a
         CMPIString object representing the right-hand side of the predicate.
     @return @parblock
         A CMPIStatus structure indicating the
         function return status will be returned.

         If not successful, @p lhs and @p rhs will be set to NULL, and the
         state of @p type and @p prop is undefined.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by the MB.
         (**Deprecated**)
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p pr handle is invalid.

     @see CMGetPredicateData()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPIStatus (*getData) (const CMPIPredicate* pr, CMPIType* type,
            CMPIPredOp* prop, CMPIString** lhs, CMPIString** rhs);

    /**
     @brief Test whether the properties returned by an accessor
         function match the predicate in a CMPIPredicate object.

     CMPIPredicateFT.evaluateUsingAccessor() tests whether the
     properties returned by an accessor function match the predicate in a
     CMPIPredicate object.

     The CMPIString objects returned by lhs and rhs shall not be explicitly
     released by the MI, because they may be internal objects of the
     CMPIContext object which will be released along with that object, or new
     objects created by the MB which will be automatically released by the
     MB
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param pr Points to the CMPIPredicate object for this function.
     @param accessorFnc Points to a property value accessor
         function. The evaluation process will invoke this function to
         request a CMPIData structure for a particular property. The
         signature of the accessor function is: CMPIData
         CMPIAccessor(const char* propertyName, void* parm);
     @param parm Parameter that will be passed to the accessor function and
         can be used for providing context data to the accessor function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPIBoolean value indicating
         the test result will be returned, as follows:
         @li True indicates that the properties returned by the
         accessor function match the predicate;
         @li False indicates that this is not the case.

         If not successful, False will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p pr handle is invalid.

     @see CMEvaluatePredicateUsingAccessor()
     @deprecated The `CMPI_RC_ERR_NOT_SUPPORTED` return code of this function
         is deprecated since CMPI 2.1. If the
         @ref CMPI_MB_QueryNormalization "Query Normalization" capability
         is not available, this function cannot be called by the MI because no
         instance of its encapsulated data type can exist.
    */
    CMPIBoolean (*evaluateUsingAccessor) (const CMPIPredicate* pr,
        CMPIAccessor* accessorFnc, void* parm, CMPIStatus* rc);

} CMPIPredicateFT;

/**
 * @}
 * @addtogroup edt-args
 * @{
 */

/**
 * @brief CMPIArgs encapsulated data type object.
 */
typedef struct _CMPIArgs {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIArgsFT* ft;

} CMPIArgs;

/**
 * @brief Function table of CMPIArgs encapsulated data type object.
 */
typedef struct _CMPIArgsFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIArgs object.

     CMPIArgsFT.release() releases a CMPIArgs object. This indicates to the
     MB that the object (including any objects it contains) will no longer
     be used by the MI. The MB may free (=reclaim) the memory associated
     with the object during the call to this function, or later during some
     garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param args Points to the CMPIArgs object to be released.
         That object shall have been created using CMPIArgsFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p args handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIArgs* args);

    /**
     @brief Create an independent copy of a CMPIRArgs object.

     CMPIArgsFT.clone() creates an independent copy of this Args object. The
     resulting object must be released explicitly.

     @param args Points to the CMPIArgs object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the copied
         CMPIArgs object will be returned.

         The returned CMPIArgs object shall be explicitly released by the MI
         using CMPIArgsFT.release().

         If not successful, NULL will be returned
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p args handle is invalid.

     @see CMClone()
    */
    CMPIArgs* (*clone) (const CMPIArgs* args, CMPIStatus* rc);

    /**
     @brief Set a method parameter in a CMPIArgs object.

     CMPIArgsFT.addArg() adds or replaces a method parameter in a CMPIArgs
     object.

     @param args Points to the CMPIArgs object for this function.
     @param name Argument name.
     @param value Points to a CMPIValue structure containing the non-NULL
         value to be assigned to the method parameter, or NULL to specify that
         NULL is to be assigned
     @param type type of the method parameter. All types of CIM values are
         supported.
         If the value of @p type is @ref CMPI_chars or
         @ref CMPI_charsA, the
         C-language string to which the chars member of @p value
         points is copied by this function and the original string memory may
         be freed by the MI right after this function returns.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_DATA_TYPE` - Data type not valid.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p args handle is invalid.

     @see CMAddArg()
    */
    CMPIStatus (*addArg) (const CMPIArgs* args, const char* name,
            const CMPIValue* value,
            const CMPIType type);

    /**
     @brief Get a method parameter in a CMPIArgs object by name.

     CMPIArgsFT.getArg() gets a method parameter in a CMPIArgs object,
     by its name.

     @param args Points to the CMPIArgs object for this function.
     @param name Specifies the name of the method parameter.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful,returns a CMPIData structure
         containing the specified method parameter.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Method parameter not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p args handle is invalid.

     @see CMGetArg()
    */
    CMPIData (*getArg) (const CMPIArgs* args, const char* name, CMPIStatus* rc);

    /**
     @brief Get a method parameter in a CMPIArgs object by index.

     CMPIArgsFT.getArgAt() gets a Argument value defined by its index.

     @param args Points to the CMPIArgs object for this function.
     @param index Position in the internal Data array.
     @param [out] name
     @parblock
         If not NULL, points to a
         CMPIString pointer that upon success will have been updated to point
         to a CMPIString object containing the method parameter name.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPIArgs object
         which will be released along with that object, or a new object
         created by the MB which will be automatically released by the
         MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").
     @endparblock
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIData structure
         containing the specified method parameter.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - Method parameter not found.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p args handle is invalid.

     @see CMGetArgAt()
    */
    CMPIData (*getArgAt) (const CMPIArgs* args, CMPICount index,
        CMPIString** name, CMPIStatus* rc);

    /**
     @brief Get a method parameter in a CMPIArgs object by index.

     CMPIArgsFT.getArgCount() gets the number of arguments contained in this
     CMPIArgs object.

     @param args Points to the CMPIArgs object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIData structure
         containing the specified method parameter.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p args handle is invalid.

     @see CMGetArgCount()
    */
    CMPICount (*getArgCount) (const CMPIArgs* args, CMPIStatus* rc);

} CMPIArgsFT;

/**
 * @}
 * @addtogroup edt-string
 * @{
 */

/**
 * @brief CMPIString encapsulated data type object.
 */
typedef struct _CMPIString {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIStringFT* ft;

} CMPIString;

/**
 * @brief Function table of CMPIString encapsulated data type object.
 */
typedef struct _CMPIStringFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIString object.

     CMPIStringFT.release() releases a CMPIString object. This indicates to
     the MB that the object (including any objects it contains) will no longer
     be used by the MI. The MB may free (=reclaim) the memory associated with
     the object during the call to this function, or later during some
     garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param str Points to the CMPIString object to be released.
         That object shall have been created using CMPIStringFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p str handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIString* str);

    /**
     @brief Create an independent copy of this String object.

     CMPIStringFT.clone() creates an independent copy of this String object.
     The resulting object must be released explicitly.

     @param str Points to the CMPIString object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the copied
         CMPIString object will be returned.

         The returned CMPIString object shall be explicitly released by the
         MI using CMPIStringFT.release().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p str handle is invalid.

     @see CMClone()
    */
    CMPIString* (*clone) (const CMPIString* str, CMPIStatus* rc);

    /**
     @brief Get a pointer to a C-language string representation of a
         CMPIString object.

     CMPIStringFT.getCharPtr() gets a pointer to a C char* representation of
     this CMPIString object.

     @param str Points to the CMPIString object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         C-language string will be returned.

         The character array of the returned string shall not be explicitly
         released by the MI, because it may point to an internal data area in
         the CMPIString object which will be released along with that object,
         or it may point to a new character array created by the MB which will
         be released automatically by the MB.

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p str handle is invalid.

     @see CMGetCharsPtr()
    */
    const char* (*getCharPtr) (const CMPIString* str, CMPIStatus* rc);

#ifdef CMPI_VER_210

    /**
     @brief Create a C-language string that has converted a CMPIString
         object into a specific codepage

     CMPIStringFT.newCharsCP() creates a new C-language string
     that contains the string in a CMPIString
     object, converted into a specific codepage.

     This function shall be supported by the MB if the
     @ref CMPI_MB_CodepageConversion "Codepage Conversion" capability
     is available; otherwise, it shall not be supported.

     @param str Points to the CMPIString object for this function.
     @param cpid CMPICodePageID specifies the CMPI-specific codepage
         ID for the codepage to convert to. See subclause 5.2.2 in the
         @ref ref-cmpi-standard "CMPI Standard" (CodePage for a list
         of supported codepages and their codepage ID values.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a new C-language
         string, in the codepage specified in @p cpid.

         The returned C-language string must be freed by the MI using
         CMPIBrokerMemFT.freeChars().

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p str handle is invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - @p cpid is invalid.
     @li `CMPI_RC_ERR_NOT_IN_CODEPAGE` - The string contains characters that
         are not representable in the specified codepage.
     @capcodepage This function is part of the Codepage Conversion
         MB capability.

     @todo KS: Add see macro
     @added210 Added in CMPI 2.1.0.
    */
    char* (*newCharsCP) (const CMPIString* str, const CMPICodepageID cpid,
        CMPIStatus* rc);

#endif /*CMPI_VER_210*/

} CMPIStringFT;

/**
 * @}
 * @addtogroup edt-array
 * @{
 */

/**
 * @brief CMPIArray encapsulated data type object.
 */
typedef struct _CMPIArray {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIArrayFT* ft;

} CMPIArray;

/**
 * @brief Function table of CMPIArray encapsulated data type object.
 */
typedef struct _CMPIArrayFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIArray object.

     CMPIArrayFT.release() releases a CMPIArray object. This indicates
     to the MB that the object (including any objects it contains) will
     no longer be used by the MI. The MB may free (=reclaim) the memory
     associated with the object during the call to this function, or
     later during some garbage collection cycle
     (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

     @param ar Points to the CMPIArray object to be released.
         That object shall have been created using CMPIArrayFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ar handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIArray* ar);

    /**
     @brief Create an independent copy of a CMPIArray object.

     CMPIArrayFT.clone() creates an independent copy of this
     CMPIArray object. The
     resulting object must be released explicitly.

     @param ar Points to the CMPIArray object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a pointer to the copied
         CMPIArray object will be returned.

         The returned CMPIArray object shall be explicitly released by the MI
         using CMPIArrayFT.release().

         If not successful, NULL will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ar handle is invalid.

     @see CMClone()
    */
    CMPIArray* (*clone) (const CMPIArray* ar, CMPIStatus* rc);

    /**
     @brief Get the number of array elements in a CMPIArray object.

     CMPIArrayFT.getSize() gets the number of array
     elements in a CMPIArray object.

     @param ar Points to the CMPIArray object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPICount value indicating
         the number of array elements will be returned.

         If not successful, 0 will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ar handle is invalid.

     @see CMGetArrayCount()
    */
    CMPICount (*getSize) (const CMPIArray* ar, CMPIStatus* rc);

    /**
     @brief Get the type of the array elements in a CMPIArray object.

     CMPIArrayFT.getSimpleType() gets the type of the array elements in a
     CMPIArray object.

     @param ar Points to the CMPIArray object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a @ref CMPIType value indicating the type of the
         CMPIArray elements will be returned. The returned value indicates the
         type of single array elements; for example, the value returned for
         a CMPIArray object that contains CMPIString objects, will be
         @ref CMPI_string, and not @ref CMPI_stringA.

         If not successful, @ref CMPI_null will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ar handle is invalid.

     @see CMGetArrayType()

    */
    CMPIType (*getSimpleType) (const CMPIArray* ar, CMPIStatus* rc);

    /**
     @brief Get the value of an array element in a CMPIArray object by index.

     CMPIArrayFT.getElementAt() gets the value of an array element defined
     by the zero-based position
     @p index of the array element in a CMPIArray object @p ar.

     @param ar Points to the CMPIArray object for this function.
     @param index Zero-based position in the CMPIArray. The position shall
         be equal to or greater than 0 and less than the size of the array.
         Returns error if index out of range of the array.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIData structure
         containing the specified array element.

         If not successful, CMPIData.state will have the @ref CMPI_badValue flag
         set to true.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - @p index value
         out of range.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ar
         handle is invalid.

     @see CMGetArrayElementAt()
    */
    CMPIData (*getElementAt) (const CMPIArray* ar, CMPICount index,
        CMPIStatus* rc);

    /**
     @brief Set the value of an existing array element in a CMPIArray object
         by index.

     CMPIArrayFT.setElementAt() sets the value @p value and @p type
     into an existing element defined by @p index in the
     array object defined by @p ar.

     @param ar Points to the CMPIArray object for this function.
     @param index zero-based position of the existing element in the
         CMPIArray object. The position shall be equal to or greater than
         0 and less than the size of the array.
     @param value Points to a CMPIValue structure containing
         the non-NULL value to be assigned to the element, or is NULL to
         specify that the element will be set to NULL.
     @param type Either the simple base type of the array or @ref CMPI_null.
         If the value of @p type is @ref CMPI_chars, the C-language
         string to which the @p chars member of @p value points is
         copied by this function and the original string memory may be
         freed by the MI right after this function returns
     @return CMPIStatus structure containing the function return status.

     If not successful, the array element's state shall be set to
     @ref CMPI_nullValue, if possible.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_NO_SUCH_PROPERTY` - @p index value out of range.
     @li `CMPI_RC_ERR_TYPE_MISMATCH` - @p type does not correspond to the
         simple base type of @p ar.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ar handle is invalid.

     @see CMSetArrayElementAt()
     @deprecated The use of @ref CMPI_null for @p type is deprecated since
         CMPI 2.1. Specify the simple base type of the array instead.
     @deprecated The behavior of setting the array element's state to
         @ref CMPI_nullValue when the function was not successful, is deprecated
         since CMPI 2.1.
         Instead, callers should assume that it is undefined whether the array
         element's state has changed when the function was not successful.
    */
    CMPIStatus (*setElementAt) (const CMPIArray* ar, CMPICount index,
        const CMPIValue* value, CMPIType type);

} CMPIArrayFT;

/**
 * @}
 * @addtogroup edt-enumeration
 * @{
 */

/**
 * @brief CMPIEnumeration encapsulated data type object.
 */
typedef struct _CMPIEnumeration {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIEnumerationFT* ft;

} CMPIEnumeration;

/**
 * @brief Function table of CMPIEnumeration encapsulated data type object.
 */
typedef struct _CMPIEnumerationFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIEnumeration object.

     CMPIEnumerationFT.release() releases a CMPIEnumeration object.
     This indicates to the MB that
     the object (including any objects it contains) will no longer
     be used by the MI. The MB may free the resources associated with
     the object during the call to this function, or later during some
     garbage collection cycle.

     @param en Points to the CMPIEnumeration object to be released.
        That object shall have been created using CMPIEnumerationFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIEnumeration* en);

    /**
     @brief Create an independent copy of a CMPIEnumeration object.

     CMPIEnumerationFT.clone() creates an independent copy of this
     CMPIEnumeration object.
     The resulting object must be released explicitly.

     @param en Points to the CMPIEnumeration object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the
         copied CMPIEnumeration object.

         The returned CMPIEnumeration object shall be explicitly released by
         the MI using CMPIEnumerationFT.release().

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p en handle is invalid.

     @see CMClone()
    */
    CMPIEnumeration* (*clone) (const CMPIEnumeration* en, CMPIStatus* rc);

    /**
     @brief Get the next element in a CMPIEnumeration object.

     CMPIEnumerationFT.getNext() gets the next element in a
     CMPIEnumeration object.

     @param en Points to the CMPIEnumeration object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, a CMPIData structure
         containing the next element will be returned.

         If not successful, CMPIData.state will have the @ref CMPI_badValue
         flag set to true
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p en handle is invalid.

     @see CMGetNext()
    */
    CMPIData (*getNext) (const CMPIEnumeration* en, CMPIStatus* rc);

    /**
     @brief Test for any elements left in a CMPIEnumeration object.

     CMPIEnumerationFT.hasNext() tests for any elements left in @p en the
     CMPIEnumeration object.

     @param en Points to the CMPIEnumeration object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIBoolean value
         indicating the test result will be returned, as follows:
         True indicates that the enumeration has more elements left;
         False indicates that this is not the case.

         If not successful, False will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p en handle is invalid.

     @see CMHasNext()
    */
    CMPIBoolean (*hasNext) (const CMPIEnumeration* en, CMPIStatus* rc);

    /**
     @brief Convert a CMPIEnumeration object to a CMPIArray object.

     CMPIEnumerationFT.toArray() converts  the CMPIEnumeration object
     represented by the argument @p en into a CMPIArray.

     @param en Points to the CMPIEnumeration object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         CMPIArray object containing the elements from the
         CMPIEnumeration object.

         The returned CMPIArray object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPIEnumeration
         object which will be released along with that object, or a new object
         created by the MB which will be released automatically by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p en handle is invalid.

     @see CMToArray()
    */
    CMPIArray* (*toArray) (const CMPIEnumeration* en, CMPIStatus* rc);

} CMPIEnumerationFT;

/**
 * @}
 * @addtogroup edt-datetime
 * @{
 */

/**
 * @brief CMPIDateTime Support (Subclause 8.9)
 */
typedef struct _CMPIDateTime {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIDateTimeFT* ft;

} CMPIDateTime;

/**
 * @brief Function table of CMPIDateTime encapsulated data type object.
 */
typedef struct _CMPIDateTimeFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIDateTime object.

     CMPIDateTimeFT.release() releases a CMPIDateTime object.
     This indicates to the MB that the
     object (including any objects it contains) will no longer be used
     by the MI. The MB may free the resources associated with the object
     during the call to this function, or later during some
     garbage collection cycle.

     @param dt Points to the CMPIDateTime object to be released.
         That object shall have been created using CMPIDateTimeFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIDateTime* dt);

    /**
     @brief Create an independent copy of a CMPIDateTime object.

     CMPIDateTimeFT.clone() creates an independent copy of @p dt a
     CMPIDateTime object. The
     resulting object must be released explicitly.

     @param dt Points to the CMPIDateTime object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful,returns a pointer to the copied
         CMPIDateTime object.

         The returned CMPIDateTime object shall be explicitly released by the MI
         using CMPIDateTimeFT.release().

         If not successful, returns NULL
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMClone()
    */
    CMPIDateTime* (*clone) (const CMPIDateTime* dt, CMPIStatus* rc);

    /**
     @brief Get the value of a CMPIDateTime object in binary format.

     CMPIDateTimeFT.getBinaryFormat() gets the value of a
     CMPIDateTime object as a 64-bit
     unsigned integer in microseconds starting since 00:00:00
     GMT, January 1, 1970, or as an interval in microseconds,
     depending on what kind of value the CMPIDateTime object
     contains.

     @param dt Points to the CMPIDateTime object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIUint64 value
         containing the value of the CMPIDateTime object in binary
         format.

         If not successful, returns 0.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMGetBinaryFormat()
    */
    CMPIUint64 (*getBinaryFormat) (const CMPIDateTime* dt,
        CMPIStatus* rc);

    /**
     @brief Get the value of a CMPIDateTime object in the string
         format defined for the CIM datetime type.

     CMPIDateTimeFT.getStringFormat() gets the value of a
     CMPIDateTime object as a string in the format defined
     in @ref ref-dmtf-dsp0004 "DSP0004" for the CIM datetime type.

     @param dt Points to the CMPIDateTime object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to a
         CMPIString object containing the value of a CMPIDateTime
         object in the format defined in @ref ref-dmtf-dsp0004
         "DSP0004" for the CIM datetime type.

         The returned CMPIString object shall not be explicitly released
         by the MI, because it may be an internal object of the CMPIDateTime
         object which will be released along with that object, or a new
         object created by the MB which will be released automatically by
         the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMGetStringFormat()
    */
    CMPIString* (*getStringFormat) (const CMPIDateTime* dt, CMPIStatus* rc);

    /**
     @brief Test whether a CMPIDateTime object contains an interval value.

     CMPIDateTimeFT.isInterval() tests whether DateTime is an interval value.

     @param dt Points to the CMPIDateTime object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIBoolean value
         indicating the test result, as follows:
         @li True indicates that the CMPIDateTime object contains an interval
         value;
         @li False indicates that this is not an interval.

         If not successful, False will be returned.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid encapsulated data type handle.

     @see CMGetStringFormat()
    */
    CMPIBoolean (*isInterval) (const CMPIDateTime* dt, CMPIStatus* rc);

} CMPIDateTimeFT;

/**
 * @}
 * @addtogroup edt-propertylist
 * @{
 */

#ifdef CMPI_VER_210

/**
 * @brief CMPIPropertyList encapsulated data type object.
 *
 * @added210 Added in CMPI 2.1.0.
 */
typedef struct _CMPIPropertyList {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIPropertyListFT* ft;

} CMPIPropertyList;

/**
 * @brief Function table of CMPIPropertyList encapsulated data type object.
 *
 * @added210 Added in CMPI 2.1.0.
 */
typedef struct _CMPIPropertyListFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIPropertyList object.

     CMPIPropertyListFT.release() releases a CMPIPropertyList object.
     This indicates to the MB that the object (including any objects it
     contains) will no longer be used by the MI. The MB may free
     the resources associated with the object during the call to
     this function, or later during some garbage collection cycle.

     @param plist Points to the CMPIPropertyList object to be released.
         That object shall have been created using CMPIPropertyListFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p plist.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIPropertyList* plist);

    /**
     @brief Create an independent copy of a CMPIPropertyList object.

     CMPIPropertyListFT.clone() creates an independent copy of @p plist,
     the CMPIPropertyList object.

     @param plist Points to the CMPIPropertyList object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return has been updated with the function return status
     @return @parblock
         If successful, returns a pointer to the
         copied CMPIPropertyList object.

         The returned CMPIPropertyList object shall be explicitly released by
         the MI using CMPIPropertyListFT.release().

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p plist.

     @see CMClone()
    */
    CMPIPropertyList* (*clone) (const CMPIPropertyList* plist, CMPIStatus* rc);

    /**
     @brief Test whether a property is in the property list
         represented by a CMPIPropertyList object.

     CMPIPropertyListFT.isPropertyInList() tests whether a property is in
     the property list represented by a CMPIPropertyList object.

     The MB's implementation of this function should be efficient. However,
     it is recommended that MIs when returning many instances invoke this
     function only once for each property, and cache the result.

     @param plist Points to the CMPIPropertyList object for this function.
     @param pname A CMPIString specifying the name of the property to be
         tested.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return has been updated with the function return status
     @return @parblock
         If successful, a CMPIBoolean value indicating
         the test result will be returned, as follows: True
         indicates that the property is in the property list; False
         indicates that this is not the case.

         If not successful, returns False.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - Invalid @p plist.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - Invalid @p pname.

     @todo KS: Find macro for this
    */
    CMPIBoolean (*isPropertyInList) (const CMPIPropertyList* plist,
        const char* pname, CMPIStatus* rc);

    /**
     @brief Return the property list represented by a CMPIPropertyList object
     as an array of strings.

     CMPIPropertyListFT.getProperties() returns the property list
     represented by @p plist CMPIPropertyList object as a NULL-terminated array
     of pointers to strings.

     @param plist Points to the CMPIPropertyList object for this function.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the first
         entry of a NULL-terminated array of pointers to strings
         that represent the property names in the property list
         represented by the CMPIPropertyList object.

         The entries in that array may be in any order and in any lexical case
         (possibly different than originally specified in
         CMPIBrokerEncFT.newPropertyList()).

         The returned array shall not be explicitly released by the MI, because
         it may point to an internal data area in the CMPIPropertyList object
         which will be released along with that object, or it may point to a
         new array created by the MB which will be released automatically
         by the MB
         (see Subclause 4.1.7 of the @ref ref-cmpi-standard "CMPI Standard").

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p plist handle is invalid.

     @todo KS: Find macro for this
    */
    const char** (*getProperties) (const CMPIPropertyList* plist,
        CMPIStatus* rc);

} CMPIPropertyListFT;

/**
 * @}
 * @addtogroup edt-enumerationfilter
 * @{
 */

/**
 * @brief CMPIEnumerationFilter Support (Subclause 8.16)
 *
 * @added210 Added in CMPI 2.1.0.
 */
typedef struct _CMPIEnumerationFilter {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this object.
     */
    const CMPIEnumerationFilterFT* ft;

} CMPIEnumerationFilter;

/**
 * @brief Function table of CMPIEnumerationFilter encapsulated data type object.
 *
 * @added210 Added in CMPI 2.1.0.
 */
typedef struct _CMPIEnumerationFilterFT {

    /**
     * @brief CMPI version supported by the MB for this function table.
     *
     * Any earlier CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     @brief Release a CMPIResult object.

     CMPIEnumerationFilterFT.release() releases a CMPIEnumerationFilter
     object. This indicates to the MB that
     the object (including any objects it contains) will no longer
     be used by the MI. The MB may free the resources associated with
     the object during the call to this function, or later during
     some garbage collection cycle.

     @param ef Points to the CMPIEnumerationFilter object to be released.
         That object shall have been created using
         CMPIEnumerationFilterFT.clone().
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ef handle is invalid.

     @see CMRelease()
    */
    CMPIStatus (*release) (CMPIEnumerationFilter* ef);

    /**
     @brief Create an independent copy of a CMPIEnumerationFilter object.

     CMPIEnumerationFilterFT.clone() creates an independent copy of the
     CMPIEnumerationFilter object defined by @p rslt.

     @param ef Points to the CMPIEnumerationFilter object to be copied.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a pointer to the
         copied CMPIEnumerationFilter object.

         The returned CMPIEnumerationFilter object shall be explicitly
         released by the MI using CMPIEnumerationFilterFT.release().

         If not successful, returns NULL.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ef handle is invalid.

     @see CMClone()
    */
    CMPIEnumerationFilter* (*clone) (const CMPIEnumerationFilter* ef,
        CMPIStatus* rc);

    /**
     @brief Instance matches the filter represented by a
         CMPIEnumerationFilter object

     CMPIEnumerationFilterFT.match() tests whether an instance matches
     the filter
     represented by the CMPIEnumerationFilter object @p ef.
     The filter matches the instance if the conditions defined in the
     filter are met by the properties of the instance.

     @param ef Points to the CMPIEnumerationFilter object for this function.
     @param inst CMPIInstance object to be tested against the filter.
     @param [out] rc If not NULL, points to a CMPIStatus structure that upon
         return will have been updated with the function return status.
     @return @parblock
         If successful, returns a CMPIBoolean value
         indicating the test result as follows: True indicates that
         the instance matches the filter; False indicates that this
         is not the case.

         If not successful, returns False.
     @endparblock

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ef handle
         is invalid.
     @li `CMPI_RC_ERR_INVALID_QUERY` - The filterQuery is not a
         valid query in the specified filter query language
     @li `CMPI_RC_ERR_QUERY_FEATURE_NOT_SUPPORTED` - A feature of
         the query language is not supported.
     @li `CMPI_RC_ERR_FAILED` - Error not defined by one of the above
         codes occurred.

     @todo KS: Create macro for this
    */
    CMPIBoolean (*match) (const CMPIEnumerationFilter* ef,
        const CMPIInstance* inst, CMPIStatus* rc);

} CMPIEnumerationFilterFT;

#endif /*CMPI_VER_210*/

/**
 * @}
 * @addtogroup instance-mi
 * @{
 */

/**
 * @brief CMPIInstanceMI object.
 *
 * This object is provided by an instance MI through
 * @ref mi-factory "MI factory functions", in order to make its MI functions
 * available to the MB.
 */
typedef struct _CMPIInstanceMI {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this MI
     *     object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this MI object.
     */
    const CMPIInstanceMIFT* ft;

} CMPIInstanceMI;

/**
 * @brief Function table of CMPIInstanceMI object.
 */
typedef struct _CMPIInstanceMIFT {

    /**
     * @brief CMPI version supported by the MI for this function table.
     *
     * Any later CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     * @brief Informal MI-specific version number for this MI.
     */
    int miVersion;

    /**
     * @brief Informal MI-specific name for this MI.
     */
    const char* miName;

    /**
     @brief Perform cleanup for an Instance MI.

     CMPIInstanceMIFT.cleanup() shall perform any necessary cleanup operation
     of the library of which this Instance MI @p mi unless the MI
     postpones the cleanup.

     While this function executes, the MB will not call any other MI functions
     for this MI. After this function returns, the MB may unload the load
     library this MI is part of, unless the MI postpones the cleanup

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param terminating
     @parblock
         When True, the MB is in the process of shutting down.
         The MI shall perform any necessary cleanup and shall not
         postpone the cleanup. After this function returns (successful
         or in error), the MB will consider this MI to be uninitialized
         and will not call further MI functions for this MI.

         When False, the MI can choose to perform or postpone the
         cleanup, by performing one of these actions:

         @li The MI performs any necessary cleanup and does not request
         postponing the cleanup. After this function returns (successful
         or in error), the MB will consider this MI to be uninitialized
         and will not call further MI functions for this MI.
         @li The MI does not perform any cleanup and temporarily
         postpones the cleanup, by returning CMPI_RC_DO_NOT_UNLOAD. This
         will cause the MB to consider this MI still to be initialized,
         and the MB may call further MI functions of this MI. The MB may
         call this function again after some MB implementation-specific
         time.
         @li The MI does not perform any cleanup and permanently
         postpones the cleanup, by returning `CMPI_RC_NEVER_UNLOAD`.
         This will cause the MB to consider this MI still to be
         initialized, and the MB may call further MI functions of this
         MI. The MB will not call this function again until the MB
         terminates (at which time the MB calls this function with
         terminating set to true).
     @endparblock
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following @ref CMPIrc codes shall be used by the MI in the
     function return status:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_DO_NOT_UNLOAD` - Operation successful - do not unload now.
     @li `CMPI_RC_NEVER_UNLOAD` - Operation successful - never unload.
    */
    CMPIStatus (*cleanup) (CMPIInstanceMI* mi, const CMPIContext* ctx,
        CMPIBoolean terminating);

    /**
     @brief Enumerate instance paths of instances of a given class serviced
         by this MI.

     CMPIInstanceMIFT.enumerateInstanceNames() enumerates the instance
     paths of instances of a given class defined by @p classPath that are
     serviced by this MI, by accessing the underlying managed elements.

     This function is provided by the MI in context of @p mi a particular
     MI name. The class of @p op for which this function will be
     called by the MB depends on the specifics of how the MB relates classes
     and MI names, which is out of scope for this standard. As a result, the
     MB may call this function for classes for which the MI is not responsible.
     In order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether it
     services the class specified in @p classPath.

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put all instance
         paths representing the result set into this container.
     @param classPath Points to CMPIObjectPath containing namespace and
         classname components. Hostname and key components, if present, have
         no meaning and should be ignored.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>N/A</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0227 + implementation
         specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*enumerateInstanceNames) (CMPIInstanceMI* mi,
        const CMPIContext* ctx, const CMPIResult* rslt,
        const CMPIObjectPath* classPath);

    /**
     @brief Enumerate the instances of a given class serviced by this MI.

     CMPIInstanceMIFT.enumerateInstances() shall enumerate the instances
     of a given class that are serviced by this MI, by accessing the
     underlying managed elements.

     This function is provided by the MI in context of @p mi
     a particular MI name. The class of @p op for which this
     function will be called by the MB depends on the specifics of how the MB
     relates classes and MI names, which is out of scope for this standard. As
     a result, the MB may call this function for classes for which the MI is
     not responsible. In order for an MI to be portable across MB
     implementations with different approaches to relate MI names and classes,
     the MI must check whether it services the class specified
     in @p classPath.

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put all instances
         representing the result set into this container.
     @param classPath Points to CMPIObjectPath containing namespace and
         classname components. Hostname and key components, if present, have no
         meaning and should be ignored.
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. This set of property names
         will reflect the effects of any invocation flags specified in the
         CMPIInvocationFlags entry of @p ctx. The end of the array
         is identified by a NULL pointer. Each returned object shall not
         include elements for any properties missing from this list. If the
         properties argument is NULL, this indicates that all properties shall
         be included in each returned object.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>N/A</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*enumerateInstances) (CMPIInstanceMI* mi,
        const CMPIContext* ctx, const CMPIResult* rslt,
        const CMPIObjectPath* classPath , const char** properties);

// DONE_AM Next function is already synced with spec.
    /**
     @brief Get an existing instance.

     CMPIInstanceMIFT.getInstance() shall get an existing instance, by
     accessing the underlying managed elements.

     This function is provided by the MI in context of a particular MI name.
     The class of the @p instPath argument for which this function will be
     called by the MB depends on the specifics of how the MB relates classes
     and MI names, which is out of scope for this standard. As a result, the
     MB may call this function for classes for which the MI is not responsible.
     In order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether it
     services the class specified in the @p instPath argument.

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put the retrieved
         instance into this container.
     @param instPath Points to a CMPIObjectPath object that references the
         instance to be retrieved and that contains the namespace, class name,
         and key components. The hostname component, if present, has no meaning
         and should be ignored.
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. This set of property names will reflect
         the effects of any invocation flags specified in the
         @ref CMPIInvocationFlags entry of @p ctx. The returned instance
         shall not include elements for any properties missing from this list.
         If @p properties is NULL, this indicates that all properties shall be
         included in the returned instance.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by this MI</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*getInstance) (CMPIInstanceMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* instPath,
        const char** properties);

    /**
     @brief Create an instance of a given class.

     CMPIInstanceMIFT.createInstance() shall create an instance of a
     given class @p op in the namespace of
     that class defined in @p op and the properties defined in @p inst.

     This function is provided by the MI in context of a particular MI
     name. The class of @p classPath for which this
     function will be called by the MB depends on the specifics of how the
     MB relates classes and MI names, which is out of scope for this
     standard. As a result, the MB may call this function for classes
     for which the MI is not responsible. In order for an MI to be
     portable across MB implementations with different approaches to
     relate MI names and classes, the MI must check whether it services
     the class specified in @p classPath.

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put the
         instance path of the created instance into this container.
     @param classPath Points to a CMPIObjectPath object that references
         the given class. The hostname and key components, if present, have
         no meaning and should be ignored.
     @param inst Points to a CMPIInstance object specifying
         property values for the new instance. The object path
         component within this CMPIInstance object has no meaning;
         it should not be provided by MBs and should not be used by
         MIs
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>Invalid filter parameters.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0228</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ALREADY_EXISTS`</TD><TD>WIPG0213</TD>
         <TD>Instance already exists.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>

     @deprecated The use of the key component in @p classPath is
         deprecated since CMPI 2.1; the key component should not be provided
         by MBs and should not be used by MIs.
    */
    CMPIStatus (*createInstance) (CMPIInstanceMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* classPath,
        const CMPIInstance* inst);

    /**
     @brief Modify property values of a given instance.

     CMPIInstanceMIFT.modifyInstance() shall modify property values of
     @p mi, a given instance with properties defined in @p modInst and using
     @p properties, an array of pointers to property names, as a filter,

     This function is provided by the MI in context of a particular MI name.
     The class in @p instPath for which this function will
     be called by the MB depends on the specifics of how the MB relates classes
     and MI names, which is out of scope for this standard. As a result, the MB
     may call this function for classes for which the MI is not responsible. In
     order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether
     it services the class specified in @p instPath.

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have left this
         container empty.
     @param instPath Points to a CMPIObjectPath object that references
         the given instance and that contains the namespace, class name,
         and key components. The hostname component, if present, has no
         meaning and should be ignored.
     @param modInst Points to a CMIPInstance object specifying new values
         for the properties to be modified. The object path component within
         this CMPIInstance object has no meaning; it should not be provided by
         MBs and should not be used by MIs.
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. The invocation flags specified in
         the CMPIInvocationFlags entry of @p ctx have no meaning
         for this function. The function shall not modify elements for any
         properties missing from this list. If @p properties
         is NULL, this indicates that all properties specified in
         @p modInst are modified
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>Invalid filter parameters.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0228</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NO_SUCH_PROPERTY`</TD><TD>WIPG0220</TD>
         <TD>No such property.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*modifyInstance) (CMPIInstanceMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* instPath,
        const CMPIInstance* modInst, const char** properties);

    /**
     @brief Delete a given instance.

     CMPIInstanceMIFT.deleteInstance() shall delete an existing instance
     defined by @p instPath.

     This function is provided by the MI in context of a particular MI name.
     The class in @p instPath for which this function will be called
     by the MB depends on the specifics of how the MB relates classes and MI
     names, which is out of scope for this standard. As a result, the MB may
     call this function for classes for which the MI is not responsible. In
     order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether
     it services the class specified in @p instPath.

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have left this
         container empty.
     @param instPath Points to a CMPIObjectPath object that references
         the given instance and that contains the namespace, class name,
         and key components. The hostname component, if present, has no
         meaning and should be ignored.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0228</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*deleteInstance) (CMPIInstanceMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* op);

    /**
     @brief Execute a query on a given class and return the query result.

     CMPIInstanceMIFT.execQuery() shall query the enumeration of instances
     of the class (and subclasses) defined
     by @p op using @p query expression.

     This function is provided by the MI in context of a particular MI name.
     The class in @p instPath for which this function will be called
     by the MB depends on the specifics of how the MB relates classes and MI
     names, which is out of scope for this standard. As a result, the MB may
     call this function for classes for which the MI is not responsible. In
     order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether
     it services the class specified in @p instPath.

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have left this
         container empty.
     @param classPath Points to a CMPIObjectPath object that references
         the given class. The hostname and key components, if present, have
         no meaning and should be ignored.
     @param query Points to a string containing the select expression.
     @param lang Points to a case-sensitive string containing the query
         language.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED`</TD>
         <TD>WIPG0221</TD>
         <TD>Query language not supported.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_QUERY_FEATURE_NOT_SUPPORTED`</TD>
         <TD>WIPG0222</TD>
         <TD>A feature of the query language is not supported.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_QUERY`</TD>
         <TD>WIPG02223</TD>
         <TD>Invalid Query.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*execQuery) (CMPIInstanceMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* classPath,
        const char* query, const char* lang);

#ifdef CMPI_VER_210

    /**
     @brief Enumerate the instances of a given class that are
         serviced by this MI, returning only those that match
         @p filterQuery.

     CMPIInstanceMIFT.enumerateInstancesFiltered() shall
     enumerate the instances of a given class that are serviced by this MI,
     returning only those instances that match @p filterQuery,
     by enumerating the underlying managed elements. The returned instances
     shall have their instance paths set. If no such instances are found,
     the function shall return success with an empty result data container.

     @param mi Points to a CMPIInstanceMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return the MI shall have put all
         instances representing the result set into this container.
     @param classPath Points to a CMPIObjectPath object that references
         the given class and that contains namespace and class name components.
         The hostname and key components, if present, have no meaning and
         should be ignored.
     @param properties If not NULL, is an array of zero or more pointers
         to strings, each specifying a property name. The end of the array
         is identified by a NULL pointer. This set of property names will
         reflect the effects of any invocation flags specified in the
         CMPIInvocationFlags entry of @p ctx. Each returned
         instance shall not include elements for any properties missing
         from this list. If @p properties is NULL, this indicates
         that all properties shall be included in each returned instance.
     @param filterquerylanguage defines the query language used by
         @p filterQuery. If it is NULL, @p filterQuery is
         ignored and no filtering is performed. Note that FQL
         (see @ref ref-dmtf-dsp0212 "DSP0212") is required
         to be supported by MIs as a query language; see Subclause 4.5(TBD).
     @param filterquery defines the query language used by the @p filterQuery
         argument. If it is NULL, @p filterQuery is ignored and
         no filtering is performed. Note that FQL (see @ref ref-dmtf-dsp0212
         "DSP0212") is required to be supported by MIs as a query language;
         see Subclause 4.5(TBD).
     @param continueOnerror Defines whether this operation may continue to
         return objects after it returns an error. If false, the MI shall
         terminate after returning an error to the result data container. If
         true, the MI may continue to return data (objects and subsequent
         errors) to the result data container after returning an error. An MI
         that cannot continue after returning an error shall ignore the value
         of @p continueOnError and shall behave as if it was
         specified as false.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD>>/TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED`</TD>
         <TD>WIPG0221</TD><TD>Query language not supported.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_QUERY_FEATURE_NOT_SUPPORTED`</TD>
         <TD>WIPG0222</TD>
         <TD>A feature of the query language is not supported.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_QUERY`</TD>
         <TD>WIPG0223</TD><TD>Invalid query.</TD></TR>
     </TABLE>

     @added210 Added in CMPI 2.1.0.
    */
    CMPIStatus (*enumerateInstancesFiltered) (CMPIInstanceMI* mi,
        const CMPIContext* ctx, const CMPIResult* rslt,
        const CMPIObjectPath* classPath,
        const char** properties, const char*filterQuerylanguage,
        const char* filterQuery, CMPIStatus* rc);

#endif /*CMPI_VER_210*/

} CMPIInstanceMIFT;

/**
 * @}
 * @addtogroup association-mi
 * @{
 */

/**
 * @brief CMPIAssociationMI object.
 *
 * This object is provided by an association MI through
 * @ref mi-factory "MI factory functions", in order to make its MI functions
 * available to the MB.
 */
typedef struct _CMPIAssociationMI {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this MI
     *     object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this MI object.
     */
    const CMPIAssociationMIFT* ft;

} CMPIAssociationMI;

/**
 * @brief Function table of CMPIAssociationMI object.
 */
typedef struct _CMPIAssociationMIFT {

    /**
     * @brief CMPI version supported by the MI for this function table.
     *
     * Any later CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     * @brief Informal MI-specific version number for this MI.
     */
    int miVersion;

    /**
     * @brief Informal MI-specific name for this MI.
     */
    const char* miName;

    /**
     @brief Perform cleanup for an @ref CMPIAssociationMI object.

     CMPIAssociationMIFT.cleanup() shall perform any necessary cleanup
     operations prior to the
     unloading of the library of which this MI group is part.

     While this function executes, the MB will not call any other MI functions
     for this MI. This function will be called once for a specific MI
     (unless the MI postpones the cleanup), even if that MI services more
     than one namespace. After this function returns, the MB may unload
     the load library this MI is part of, unless the MI postpones the
     cleanup.

     @param mi Points to a CMPIAssociationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation. The context data entries are MB
         implementation-specific.
     @param terminating
     @parblock
         When true, the MB is in the process of shutting down.he MI shall
         perform any necessary cleanup and shall not postpone the cleanup.
         After this function returns (successful or in error), the MB will
         consider this MI to be uninitialized and will not call further MI
         functions for this MI.

         When false, the MI can choose to perform or postpone the cleanup, by
         performing one of these actions:
         @li The MI performs any necessary cleanup and does not request
             postponing the cleanup. After this function returns (successful
             or in error), the MB will consider this MI to be uninitialized and
             will not call further MI functions for this MI.
         @li The MI does not perform any cleanup and temporarily postpones the
             cleanup, by returning CMPI_RC_DO_NOT_UNLOAD. This will cause the
             MB to consider this MI still to be initialized, and the MB may
             call further MI functions of this MI. The MB may call this
             function again after some MB implementation-specific time.
         @li The MI does not perform any cleanup and permanently postpones the
             cleanup, by returning CMPI_RC_NEVER_UNLOAD. This will cause the MB
             to consider this MI still to be initialized, and the MB may call
             further MI functions of this MI. The MB will not call this function
             again, until the MB terminates (at which time the MB calls this
             function with @p terminating set to true).
     @endparblock
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following @ref CMPIrc codes shall be used by the MI in the
     function return status:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_DO_NOT_UNLOAD` - Function successful, do not
         unload now; the MB may retry an unload later.
     @li `CMPI_RC_NEVER_UNLOAD` - Function successful, never
         unload; the MB will not retry an unload later unless it
         shuts down.
    */
    CMPIStatus (*cleanup) (CMPIAssociationMI* mi, const CMPIContext* ctx,
        CMPIBoolean terminating);

    /**
     @brief Enumerate the instances associated with a given source instance
         that are serviced by this MI.

     CMPIAssociationMIFT.associators() shall enumerate the
     instances associated with a given source instance and that are serviced
     by this MI, by accessing the underlying managed elements.

     This function is provided by the MI in context of a particular MI name.
     The class of @p instPath for which this function will
     be called by the MB depends on the specifics of how the MB relates classes
     and MI names, which is out of scope for this standard. As a result, the MB
     may call this function for classes for which the MI is not responsible. In
     order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether it
     services the class specified in @p instPath.

     @param mi Points to a CMPIAssociationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put all
         instance paths representing the result set into this container.
     @param instPath Points to a CMPIObjectPath object that references the
         given source instance and that contains the namespace, class name,
         and key components. The hostname component, if present,
         has no meaning and should be ignored. If the source instance
         does not exist, this function shall either return success with
         an empty result data container or CMPI_RC_ERR_NOT_FOUND.
         (**Deprecated**)
     @param role If not NULL, MUST be a valid Property name.
         It acts as a filter on the returned set of Objects by mandating
         that each returned Object MUST be associated to the source Object
         via an Association in which the source Object plays the specified role
         (i.e. the name of the Property in the Association Class that refers
         to the source Object MUST match the value of this parameter).
     @param resultRole If not NULL, MUST be a valid Property name.
         It acts as a filter on the returned set of Objects by mandating
         that each returned Object MUST be associated to the source Object
         via an Association in which the returned Object plays the specified
         role (i.e. the name of the Property in the Association Class that
         refers to the returned Object MUST match the value of this parameter).
     @param properties If not NULL, the members of the array define one or more
         Property names. Each returned Object MUST NOT include elements for any
         Properties missing from this list. If NULL all properties must be
         returned.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>Invalid filter parameters.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*associators) (CMPIAssociationMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* op,
        const char* asscClass, const char* resultClass, const char* role,
        const char* resultRole, const char** properties);

    /**
     @brief Enumerate the instance paths of instances associated with a given
         source instance that are serviced by this MI.

     CMPIAssociationMIFT.associatorNames() shall enumerate
     the instance paths of instances associated with a given source instance
     and that are serviced by this MI, by accessing the underlying managed
     elements.

     This function is provided by the MI in context of a particular MI name.
     The class of @p instPath for which this function will
     be called by the MB depends on the specifics of how the MB relates classes
     and MI names, which is out of scope for this standard.  As a result, the
     MB may call this function for classes for which the MI is not responsible.
     In order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether it
     services the class specified in @p instPath.

     @param mi Points to a CMPIAssociationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put all
         instance paths representing the result set into this container.
     @param instPath Points to a CMPIObjectPath object that references the
         given source instance and that contains the namespace, class name,
         and key components. The hostname component, if present,
         has no meaning and should be ignored. If the source instance
         does not exist, this function shall either return success with
         an empty result data container or CMPI_RC_ERR_NOT_FOUND.
         (**Deprecated**)
     @param assocClass If not NULL, MUST be a valid Association Class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object MUST be associated to the source Object via an
         instance of this class or one of its subclasses.
     @param resultClass If not NULL, MUST be a valid Class name.
         It acts as a filter on the returned set of Objects by mandating that
         each returned Object MUST be either an Instance of this Class (or one
         of its subclasses).
     @param role If not NULL, MUST be a valid Property name.
         It acts as a filter on the returned set of Objects by mandating
         that each returned Object MUST be associated to the source Object
         via an Association in which the source Object plays the specified role
         (i.e. the name of the Property in the Association Class that refers
         to the source Object MUST match the value of this parameter).
     @param resultRole If not NULL, MUST be a valid Property name.
         It acts as a filter on the returned set of Objects by mandating
         that each returned Object MUST be associated to the source Object
         via an Association in which the returned Object plays the specified
         role (i.e. the name of the Property in the Association
         Class that refers to the returned Object MUST match the
         value of this parameter).
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>Invalid filter parameters.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*associatorNames) (CMPIAssociationMI* mi,
        const CMPIContext* ctx, const CMPIResult* rslt,
        const CMPIObjectPath* instPath, const char* assocClass,
        const char* resultClass, const char* role, const char* resultRole);

    /**
     @brief Enumerate the instance paths of instances associated
         with a given source instance that are serviced by this MI.

     CMPIAssociationMIFT.associatorNames() shall
     enumerate the instance paths of instances associated with @p instPath
     a given source instance and that are serviced by this MI, by accessing
     the underlying managed elements.

     If the @p assocClass or @p resultClass filters are specified
     in a call to this function, the MB is not required to scope calls to this
     function to only the MIs that service these classes.  As a result, the MB
     may (and will, in most implementations) call this function for classes in
     the @p assocClass or @p resultClass arguments for which the MI
     is not responsible.  In order for an MI to be portable across MB
     implementations, the MI must check whether it services the classes
     specified in the @p assocClass and @p resultClass arguments.

     @param mi Points to a CMPIAssociationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container.
     @param instPath Points to a CMPIObjectPath object that references
         the given source instance and that contains the namespace,
         class name, and key components. The hostname component,
         if present, has no meaning and should be ignored.
         If the source instance does not exist, this function
         shall either return success with an empty result data
         container or CMPI_RC_ERR_NOT_FOUND. (**Deprecated**)
     @param resultClass If not NULL, MUST be a valid Class name.
         It acts as a filter on the returned set of Objects by mandating that
         each returned Object MUST be either an Instance of this Class (or one
         of its subclasses).
     @param role If not NULL, MUST be a valid Property name.
         It acts as a filter on the returned set of Objects by mandating
         that each returned Object MUST be associated to the source Object
         via an Association in which the source Object plays the specified role
         (i.e. the name of the Property in the Association Class that refers
         to the source Object MUST match the value of this parameter).
     @param properties If not NULL, the members of the array define one or
         more Property names. Each returned Object MUST NOT include
         elements for any Properties missing from this list
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>Invalid filter parameters.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*references) (CMPIAssociationMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* op,
        const char* resultClass, const char* role,
        const char** properties);

    /**
     @brief Enumerate the instance paths of association instances
         referencing a given source instance that are serviced by this MI.

     CMPIAssociationMIFT.referenceNames() shall enumerate
     the instance paths of the association instances referencing a given
     source instance and that are serviced by this MI, by accessing the
     underlying managed elements.

     This function is provided by the MI in context of a particular MI name.
     The class of @p instPath for which this function will be called
     by the MB depends on the specifics of how the MB relates classes and MI
     names, which is out of scope for this standard. As a result, the MB may
     call this function for classes for which the MI is not responsible. In
     order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether it
     services the class specified in @p instPath.

     @param mi Points to a CMPIAssociationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put all
         instance paths representing the result set into this container.
     @param instPath Points to a CMPIObjectPath object that references the
         given source instance and that contains the namespace, class name,
         and key components. The hostname component, if present,
         has no meaning and should be ignored. If the source instance
         does not exist, this function shall either return success with
         an empty result data container or CMPI_RC_ERR_NOT_FOUND.
         (**Deprecated**)
     @param resultClass If not NULL, MUST be a valid Class name.
         It acts as a filter on the returned set of Objects by mandating that
         each returned Object MUST be either an Instance of this Class (or one
         of its subclasses).
     @param role If not NULL, MUST be a valid Property name.
         It acts as a filter on the returned set of Objects by mandating
         that each returned Object MUST be associated to the source Object
         via an Association in which the source Object plays the specified role
         (i.e. the name of the Property in the Association Class that refers
         to the source Object MUST match the value of this argument).
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>Invalid filter parameters.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*referenceNames) (CMPIAssociationMI* mi,
            const CMPIContext* ctx, const CMPIResult* rslt,
            const CMPIObjectPath* instPath, const char* resultClass,
            const char* role);

#ifdef CMPI_VER_210

    /**
     @brief Enumerate the instances associated with a given
         source instance serviced by this MI, returning only instances
         that match @p filterQuery.

     CMPIAssociationMIFT.associatorsFiltered() shall
     enumerate instances associated with a source instance and that
     are serviced by this MI, returning only those instances that
     match the `filterQuery argument`, by accessing the underlying
     managed elements. The returned instances shall have their
     instance paths set. If no such instances are found, the
     function shall return success with an empty result data
     container.

     @param mi Points to a CMPIAssociationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put all
         instance paths representing the result set into this container.
     @param instPath Points to a CMPIObjectPath object that references the
         given source instance and that contains the namespace, class name,
         and key components. The hostname component, if present,
         has no meaning and should be ignored. If the source instance
         does not exist, this function shall either return success with
         an empty result data container or CMPI_RC_ERR_NOT_FOUND.
         (**Deprecated**)
     @param assocClass if not NULL, shall be a valid association class name.
         It acts as a filter on the returned set of objects by mandating that
         each returned object shall be associated with the source object via
         an instance of this class or one of its subclasses.
     @param resultClass If not NULL, MUST be a valid Class name.
         It acts as a filter on the returned set of Objects by mandating that
         each returned Object MUST be either an Instance of this Class (or one
         of its subclasses).
     @param role If not NULL, MUST be a valid Property name.
         It acts as a filter on the returned set of Objects by mandating
         that each returned Object MUST be associated to the source Object
         via an Association in which the source Object plays the specified role
         (i.e. the name of the Property in the Association Class that refers
         to the source Object MUST match the value of this argument).
     @param resultRole if not NULL, shall be a valid property name.
         It acts as a filter on the returned set of objects by
         mandating that each returned object shall be associated
         with the source object via an association in which the
         returned object plays the specified role (i.e., the name of
         the property in the association class that refers to the
         returned object shall match the value of this argument).
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. The invocation flags specified in the
         CMPIInvocationFlags entry of @p ctx have no meaning for
         this function. Each returned instance shall not include elements for
         any properties missing from this list. If @p properties is
         NULL, this indicates that all properties shall be included in each
         returned instance.
     @param filterQueryLanguage defines the query language used by
         @p filterQuery. If it is NULL, @p filterQuery
         is ignored and no filtering is performed. Note that FQL
         (see @ref ref-dmtf-dsp0212 "DSP0212") is required
         to be supported by MIs as a query language; see Subclause 4.5(TBD).
     @param filterQuery defines the query in the query language defined by
         @p filterQueryLanguage. If NULL, no filtering is performed.
         A request that specifies a filter through valid and non-NULL
         @p filterQueryLanguage and @p filterQuery arguments shall return only
         instances that match that filter as defined in the
         filter specification.
     @param continueOnError defines whether this operation may continue to
         return objects after it returns an error. If false, the MI shall
         terminate after returning an error to the result data container.
         If true, the MI may continue to returning data (objects and subsequent
         errors) to the result data container after returning an error. An MI
         that cannot continue after returning an error shall ignore the value
         of @p continueOnError and shall behave as if it was
         specified as false.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>Invalid filter parameters.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>

     @added210 Added in CMPI 2.1.0.
    */
    CMPIStatus (*associatorsFiltered) (CMPIAssociationMI* mi,
        const CMPIContext* ctx, const CMPIResult* rslt,
        const CMPIObjectPath* instPath, const char* assocClass,
        const char* resultClass, const char* role, const char* resultRole,
        const char** properties, const char* filterQueryLanguage,
        const char* filterQuery, CMPIBoolean continueOnError);

    /**
     @brief Enumerate the association instances referencing a given source
     instance that are serviced by this MI, returning only those instances
     that match @p filterQuery.

     CMPIAssociationMIFT.referencesFiltered() shall
     enumerate the association instances referencing a given source instance
     and that are serviced by this MI, returning only those instances that
     match @p filterQuery, by accessing the underlying managed
     elements. The returned instances shall have their instance paths set.
     If no such instances are found, the function shall return success with
     an empty result data container.

     @param mi Points to a CMPIAssociationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put all
         instance paths representing the result set into this container.
     @param instPath Points to a CMPIObjectPath object that references the
         given source instance and that contains the namespace, class name,
         and key components. The hostname component, if present,
         has no meaning and should be ignored. If the source instance
         does not exist, this function shall either return success with
         an empty result data container or CMPI_RC_ERR_NOT_FOUND.
         (**Deprecated**)
     @param resultClass If not NULL, MUST be a valid Class name.
         It acts as a filter on the returned set of Objects by mandating that
         each returned Object MUST be either an Instance of this Class (or one
         of its subclasses).
     @param role If not NULL, MUST be a valid Property name.
         It acts as a filter on the returned set of Objects by mandating
         that each returned Object MUST be associated to the source Object
         via an Association in which the source Object plays the specified role
         (i.e. the name of the Property in the Association Class that refers
         to the source Object MUST match the value of this argument).
     @param properties If not NULL, is an array of zero or more pointers to
         strings, each specifying a property name. The end of the array is
         identified by a NULL pointer. The invocation flags specified in the
         CMPIInvocationFlags entry of @p ctx have no meaning for
         this function. Each returned instance shall not include elements for
         any properties missing from this list. If @p properties is
         NULL, this indicates that all properties shall be included in each
         returned instance.
     @param filterQueryLanguage defines the query language used by
         @p filterQuery. If it is NULL, @p filterQuery
         is ignored and no filtering is performed. Note that FQL
         (see @ref ref-dmtf-dsp0212 "DSP0212") is required
         to be supported by MIs as a query language; see Subclause 4.5(TBD).
     @param filterQuery defines the query in the query language defined by
         @p filterQueryLanguage. If NULL, no filtering is performed.
         A request that specifies a filter through valid and non-NULL
         @p filterQueryLanguage and @p filterQuery arguments shall return only
         instances that match that filter as defined in the
         filter specification.
     @param continueOnError defines whether this operation may continue to
         return objects after it returns an error. If false, the MI shall
         terminate after returning an error to the result data container.
         If true, the MI may continue to returning data (objects and subsequent
         errors) to the result data container after returning an error. An MI
         that cannot continue after returning an error shall ignore the value
         of @p continueOnError and shall behave as if it was
         specified as false.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>Invalid filter parameters.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found. Instead of using this return code if the source
         instance does not exist, the MI should return success with an empty
         result data container. The MB shall treat this return code as a
         successful return of an empty result set. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>

     @added210 Added in CMPI 2.1.0.
    */
    CMPIStatus (*referencesFiltered) (CMPIAssociationMI* mi,
        const CMPIContext* ctx, const CMPIResult* rslt,
        const CMPIObjectPath* instPath, const char* resultClass,
        const char* role, const char** properties,
        const char* filterQueryLanguage, const char* filterQuery,
        CMPIBoolean continueOnError);

#endif /*CMPI_VER_210*/

} CMPIAssociationMIFT;

/**
 * @}
 * @addtogroup method-mi
 * @{
 */

/**
 * @brief CMPIMethodMI object.
 *
 * This object is provided by a method MI through
 * @ref mi-factory "MI factory functions", in order to make its MI functions
 * available to the MB.
 */
typedef struct _CMPIMethodMI {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this MI
     *     object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this MI object.
     */
    const CMPIMethodMIFT* ft;

} CMPIMethodMI;

/**
 * @brief Function table of CMPIMethodMI object.
 */
typedef struct _CMPIMethodMIFT {

    /**
     * @brief CMPI version supported by the MI for this function table.
     *
     * Any later CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     * @brief Informal MI-specific version number for this MI.
     */
    int miVersion;

    /**
     * @brief Informal MI-specific name for this MI.
     */
    const char* miName;

    /**
     @brief Perform cleanup for an Instance MI.

     CMPIMethodMIFT.cleanup() shall perform any
     necessary cleanup operation prior to the unloading of the
     library of which this MI group is part. This function is called
     prior to the unloading of the provider.

     @param mi Points to a CMPIMethodMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param terminating When true, @p terminating indicates that
         the MB is in the process of terminating and that cleanup must be done.
         When set to false, the MI may respond with CMPI_IRC_DO_NOT_UNLOAD,
         or CMPI_IRC_NEVER_UNLOAD, indicating that unload will
         interfere with current MI processing.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following @ref CMPIrc codes shall be used by the MI in the
     function return status:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_DO_NOT_UNLOAD` - Operation successful - do not unload now.
     @li `CMPI_RC_NEVER_UNLOAD` - Operation successful - never unload.
    */
    CMPIStatus (*cleanup) (CMPIMethodMI* mi, const CMPIContext* ctx,
        CMPIBoolean terminating);

    /**
     @brief Invoke a method on a target object.

     CMPIMethodMIFT.invokeMethod() shall invoke a named,
     extrinsic method on a target object, by accessing the underlying
     managed elements. Instance methods (i.e., non-static methods)
     can be invoked only on instances. Class methods (i.e., static methods)
     can be invoked on instances and classes

     This function is provided by the MI in context of a particular
     MI name. The class of @p objPath for which this function
     will be called by the MB depends on the specifics of how the MB
     relates classes and MI names, which is out of scope for this
     standard. As a result, the MB may call this function for classes
     for which the MI is not responsible. In order for an MI to be
     portable across MB implementations with different approaches
     to relate MI names and classes, the MI must check whether
     it services the class specified in @p objPath.

     @param mi Points to a CMPIMethodMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put the
         return value of the method into this container.
         The CMPIResultFT function to be used for that depends on the
         data type of the method return, as follows:
     @li Return values declared as embedded instances (see Subclause
         4.1.3) shall be returned using
         CMPIResultFT.returnInstance().
     @li Return values declared with type `ref <classname>` (see
         Subclause 4.1.3(TBD)) shall be returned using
         CMPIResultFT.returnObjectPath().
     @li Any other return values shall be returned using
         CMPIResultFT.returnData().
     @param objPath Points to the CMPIObjectPath object that references
         the target object on which the method is invoked. If the target
         object is an instance, this object path will contain the namespace,
         class name, and key components. The hostname component, if present,
         has no meaning and should be ignored. If the target object is
         a class, this object path will contain the namespace and
         class name components. The hostname and key components,
         if present, have no meaning and should be ignored.
     @param method Points to a string containing the method name.
     @param in Points to a CMPIArgs object (whether the
         method has any input parameters or not) that contains the
         method input parameters.
     @param [out] out Points to an empty CMPIArgs object
         (whether the method has any output parameters or not) that,
         upon successful return of the method, shall have been
         updated by the MI to contain the method output parameters.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>N/A</TD>
         <TD>Function is not supported by this MI. Use
         CMPI_RC_ERR_METHOD_NOT_AVAILABLE instead.
         (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_METHOD_NOT_AVAILABLE`</TD><TD>WIPG0219</TD>
         <TD>Function is not suppored by this MI.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>WIPG0249</TD>
         <TD>The parameter is invalid. This condition is already verified by the
         MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_SERVER_LIMITS_EXCEEDED`</TD><TD>WIPG0240</TD>
         <TD>Limits Exceeded.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
    */
    CMPIStatus (*invokeMethod) (CMPIMethodMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* objPath,
        const char* method, const CMPIArgs* in, CMPIArgs* out);

} CMPIMethodMIFT;

/**
 * @}
 * @addtogroup property-mi
 * @{
 */

/**
 * @brief CMPIPropertyMI object.
 *
 * This object is provided by a property MI through
 * @ref mi-factory "MI factory functions", in order to make its MI functions
 * available to the MB.
 *
 * @deprecated Property MIs are deprecated since CMPI 2.1,
 *     in accord with the deprecation of property client operations in
 *     DMTF specifications.
 */
typedef struct _CMPIPropertyMI {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this MI
     *     object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this MI object.
     */
    const CMPIPropertyMIFT* ft;

} CMPIPropertyMI;

/**
 * @brief Function table of CMPIPropertyMI object.
 */
typedef struct _CMPIPropertyMIFT {

    /**
     * @brief CMPI version supported by the MI for this function table.
     *
     * Any later CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     * @brief Informal MI-specific version number for this MI.
     */
    int miVersion;

    /**
     * @brief Informal MI-specific name for this MI.
     */
    const char* miName;

    /**
     @brief Perform cleanup for a Property MI. (**Deprecated**)

     CMPIPropertyMIFT.cleanup() shall perform any necessary cleanup
     operations prior to the
     unloading of the library of which this MI group is part.

     While this function executes, the MB will not call any other MI functions
     for this MI. This function will be called once for a specific MI
     (unless the MI postpones the cleanup), even if that MI services more
     than one namespace. After this function returns, the MB may unload
     the load library this MI is part of, unless the MI postpones the
     cleanup.

     @param mi Points to a CMPIPropertyMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         The context data entries are MB implementation-specific.
     @param terminating
     @parblock
         When true, the MB is in the process of shutting down.
         The MI shall perform any necessary cleanup and shall not postpone
         the cleanup. After this function returns (successful or in error),
         the MB will consider this MI to be uninitialized and will not call
         further MI functions for this MI.

         When false, the MI can choose to perform or postpone the cleanup, by
         performing one of these actions:
         @li The MI performs any necessary cleanup and does not request
         postponing the cleanup. After this function returns (successful
         or in error), the MB will consider this MI to be uninitialized
         and will not call further MI functions for this MI.
         @li The MI does not perform any cleanup and temporarily
         postpones the cleanup, by returning CMPI_RC_DO_NOT_UNLOAD. This
         will cause the MB to consider this MI still to be initialized,
         and the MB may call further MI functions of this MI. The MB may
         call this function again after some MB implementation-specific
         time.
         @li The MI does not perform any cleanup and permanently
         postpones the cleanup, by returning CMPI_RC_NEVER_UNLOAD. This
         will cause the MB to consider this MI still to be initialized,
         and the MB may call further MI functions of this MI. The MB
         will not call this function again, until the MB terminates (at
         which time the MB calls this function with terminating set to
         true).
     @endparblock
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following @ref CMPIrc codes shall be used by the MI in the
     function return status:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_DO_NOT_UNLOAD` - Function successful - do not
         unload now; the MB may retry an unload later.
     @li `CMPI_RC_NEVER_UNLOAD` - Function successful - never
         unload; the MB will not retry an unload later unless it
         shuts down.

     @deprecated This function is deprecated since CMPI 2.1, in accord with the
         deprecation of property client operations in DMTF specifications.
    */
    CMPIStatus (*cleanup) (CMPIPropertyMI* mi, const CMPIContext* ctx,
            CMPIBoolean terminating); /*Deprecated*/

    /**
     @brief Set or modify the value of a property of a given instance.
         (**Deprecated**)

     CMPIPropertyMIFT.setProperty() shall set or modify the named property
     value of an instance defined by the @p instPath parameter.

     This function is provided by the MI in context of a particular MI name.
     The class of @p instPath for which this function will be
     called by the MB depends on the specifics of how the MB relates
     classes and MI names, which is out of scope for this standard. As
     a result, the MB may call this function for classes for which the
     MI is not responsible. In order for an MI to be portable across
     MB implementations with different approaches to relate MI names
     and classes, the MI must check whether it services the class
     specified in @p instPath.

     @param mi Points to a CMPIPropertyMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have
         left this container empty.
     @param instPath Points to a CMPIObjectPath object that
         references the given instance and that contains the
         namespace, class name, and key components. The hostname
         component, if present, has no meaning and should be
         ignored.
     @param name Points to a string specifying the property name.
     @param data CMPIData structure specifying the value to be assigned
         to the property
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_NAMESPACE`</TD><TD>N/A</TD>
         <TD>The namespace is invalid. This condition is already verified by the
         MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>N/A</TD>
         <TD>The parameter is invalid. This condition is already verified by the
         MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_CLASS`</TD><TD>N/A</TD>
         <TD>The CIM class does not exist. This condition is already verified by
         the MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NO_SUCH_PROPERTY`</TD><TD>WIPG0220</TD>
         <TD>No such property.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
     @deprecated This function is deprecated since CMPI 2.1, in accord with the
         deprecation of property client operations in DMTF specifications.
    */
    CMPIStatus (*setProperty) (CMPIPropertyMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* op, const char* name,
        const CMPIData data);

    /**
     @brief Retrieve property value of a given instance. (**Deprecated**)

     CMPIPropertyMIFT.getProperty() shall get the named property value
     of an instance defined by the @p instPath parameter.

     @param mi Points to a CMPIPropertyMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt Points to a CMPIResult object that is the result data
         container. Upon successful return, the MI shall have put the
         retrieved property value into this container.
         The CMPIResultFT function to be used for that depends on the data
         type of the property, as follows:
         @li The values of properties declared as embedded instances
            (see Subclause 4.1.3(TBD)) shall be returned using
            CMPIResultFT.returnInstance().
         @li The values of references (see Subclause 4.1.3(TBD)) shall be
            returned using CMPIResultFT.returnObjectPath().
         @li Any other property values shall be returned using
            CMPIResultFT.returnData().
     @param instPath Points to a CMPIObjectPath object that references
         the given instance and that contains the namespace, class name,
         and key components. The hostname component, if present, has no
         meaning and should be ignored.
     @param name Points to a string specifying the property name
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_NAMESPACE`</TD><TD>N/A</TD>
         <TD>The namespace is invalid. This condition is already verified by the
         MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>N/A</TD>
         <TD>The parameter is invalid. This condition is already verified by the
         MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_CLASS`</TD><TD>N/A</TD>
         <TD>The CIM class does not exist. This condition is already verified by
         the MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NO_SUCH_PROPERTY`</TD><TD>WIPG0220</TD>
         <TD>No such property.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
     @deprecated This function is deprecated since CMPI 2.1, in accord with the
         deprecation of property client operations in DMTF specifications.
    */
    CMPIStatus (*getProperty) (CMPIPropertyMI* mi, const CMPIContext* ctx,
        const CMPIResult* rslt, const CMPIObjectPath* instPath,
        const char* name);

#ifdef CMPI_VER_200

    /**
     @brief Set or modify the value of a property of a given
            instance. (**Deprecated**)

     CMPIPropertyMIFT.setPropertyWithOrigin()  shall set or modify the value
     and origin of a property of an existing instance, by accessing the
     underlying managed elements.

     This function is provided by the MI in context of a particular MI name.
     The class of @p instPath for which this function will be called
     by the MB depends on the specifics of how the MB relates classes and MI
     names, which is out of scope for this standard. As a result, the MB may
     call this function for classes for which the MI is not responsible. In
     order for an MI to be portable across MB implementations with different
     approaches to relate MI names and classes, the MI must check whether it
     services the class specified in @p instPath.

     @param mi Points to a CMPIPropertyMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param rslt points to a CMPIResult object that is the result data
     container. Upon successful return, the MI shall have left this
     container empty.
     @param instPath points to a CMPIObjectPath object that references the
     instance to be retrieved and that contains the namespace, class name,
     and key components. The hostname component, if present, has no meaning
     and should be ignored.
     @param name points to a string specifying the property name.
     @param data a CMPIData structure specifying the value to be assigned
     to the property.
     @param origin points to a string specifying the origin (class name) to be
     set for the property. If NULL, no origin is set for the property.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following table lists the @ref CMPIrc codes that shall be used by the
     MI in the function return status, as well as the WBEM operation messages
     that should be used in the CMPIError object if the MI supports
     extended error handling (see the corresponding
     @ref CMPI_MB_Supports_Extended_Error "Extended Errors" MB capability):
     <TABLE>
     <TR><TH>CMPIRCCode</TH><TH>CMPIErrorMsg</TH><TH>Description</TH></TR>
     <TR><TD>`CMPI_RC_OK`</TD><TD>N/A</TD>
         <TD>Function Successful</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_NAMESPACE`</TD><TD>N/A</TD>
         <TD>The namespace is invalid. This condition is already verified by the
         MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_PARAMETER`</TD><TD>N/A</TD>
         <TD>The parameter is invalid. This condition is already verified by the
         MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_INVALID_CLASS`</TD><TD>N/A</TD>
         <TD>The CIM class does not exist. This condition is already verified by
         the MB. (**Deprecated**)</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_SUPPORTED`</TD><TD>WIPG0228</TD>
         <TD>Function is not supported by the MB</TD></TR>
     <TR><TD>`CMPI_RC_ERR_ACCESS_DENIED`</TD><TD>WIPG0201</TD>
         <TD>Not authorized.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NOT_FOUND`</TD><TD>WIPG0213</TD>
         <TD>Instance not found.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_NO_SUCH_PROPERTY`</TD><TD>WIPG0220</TD>
         <TD>No such property.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD><TD>WIPG0243</TD>
         <TD>Timeout occurred.</TD></TR>
     <TR><TD>`CMPI_RC_ERR_FAILED`</TD>
         <TD>WIPG0227 + implementation-specific message</TD>
         <TD>Other error occurred.</TD></TR>
     </TABLE>
     @added200 Added in CMPI 2.0.0.
     @deprecated This function is deprecated since CMPI 2.1, in accord with the
         deprecation of property client operations in DMTF specifications.
    */
    CMPIStatus (*setPropertyWithOrigin) (CMPIPropertyMI* mi,
        const CMPIContext* ctx, const CMPIResult* rslt,
        CMPIObjectPath* instPath, const char* name, const CMPIData data,
        const char* origin);

#endif /*CMPI_VER_200*/

} CMPIPropertyMIFT;

/**
 * @}
 * @addtogroup indication-mi
 * @{
 */

/**
 * @brief CMPIIndicationMI object.
 *
 * This object is provided by an indication MI through
 * @ref mi-factory "MI factory functions", in order to make its MI functions
 * available to the MB.
 */
typedef struct _CMPIIndicationMI {

    /**
     * @brief Opaque pointer to MB-specific implementation data for this MI
     *     object.
     */
    const void* hdl;

    /**
     * @brief Pointer to the function table for this MI object.
     */
    const CMPIIndicationMIFT* ft;

} CMPIIndicationMI;

/**
 * @brief Function table of CMPIIndicationMI object.
 */
typedef struct _CMPIIndicationMIFT {

    /**
     * @brief CMPI version supported by the MI for this function table.
     *
     * Any later CMPI versions are implicitly also supported.
     *
     * See @ref sym-version-nnn "CMPIVersion{NNN}" for valid CMPI
     * version numbers.
     */
    CMPIVersion ftVersion;

    /**
     * @brief Informal MI-specific version number for this MI.
     */
    int miVersion;

    /**
     * @brief Informal MI-specific name for this MI.
     */
    const char* miName;

    /**
     @brief Perform cleanup for an Indication MI.

     CMPIIndicationMIFT.cleanup() shall perform any necessary cleanup
     operations prior to the
     unloading of the library of which this MI group is part.

     While this function executes, the MB will not call any other MI functions
     for this MI. This function will be called once for a specific MI
     (unless the MI postpones the cleanup), even if that MI services more
     than one namespace. After this function returns, the MB may unload
     the load library this MI is part of, unless the MI postpones the
     cleanup.

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         The context data entries are MB implementation-specific.
     @param terminating
     @parblock
         When true, the MB is in the process of shutting down.
         The MI shall perform any necessary cleanup and shall not postpone
         the cleanup. After this function returns (successful or in error),
         the MB will consider this MI to be uninitialized and will not call
         further MI functions for this MI.

         When false, the MI can choose to perform or postpone the cleanup, by
         performing one of these actions:
         @li The MI performs any necessary cleanup and does not request
         postponing the cleanup. After this function returns (successful
         or in error), the MB will consider this MI to be uninitialized
         and will not call further MI functions for this MI.
         @li The MI does not perform any cleanup and temporarily
         postpones the cleanup, by returning CMPI_RC_DO_NOT_UNLOAD. This
         will cause the MB to consider this MI still to be initialized,
         and the MB may call further MI functions of this MI. The MB may
         call this function again after some MB implementation-specific
         time.
         @li The MI does not perform any cleanup and permanently
         postpones the cleanup, by returning CMPI_RC_NEVER_UNLOAD. This
         will cause the MB to consider this MI still to be initialized,
         and the MB may call further MI functions of this MI. The MB
         will not call this function again, until the MB terminates (at
         which time the MB calls this function with terminating set to
         true).
     @endparblock
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The following @ref CMPIrc codes shall be used by the MI in the
     function return status:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_DO_NOT_UNLOAD` - Function successful, do not
         unload now; the MB may retry an unload later.
     @li `CMPI_RC_NEVER_UNLOAD` - Function successful, never unload;
         the MB will not retry an unload later unless it shuts down.
    */
    CMPIStatus (*cleanup) (CMPIIndicationMI* mi, const CMPIContext* ctx,
            CMPIBoolean terminating);

    /**
     @brief Ask an MI to verify whether an indication filter is
         supported by the MI.

     CMPIIndicationMIFT.authorizeFilter() shall verify whether an
     indication filter is supported by the MI.

     An MB implementation is free to choose whether this function is called
     when the MB starts up independently of whether or not there are
     any subscriptions for the filter, or only when the first
     subscription to the filter is made.

     In any case, for any particular filter this function is called on,
     it shall be called by the MB before CMPIIndicationMIFT.activateFilter()
     is called for the first time on the same filter.

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         There is no defined client operation that determines the context data.
         As a result, not all context data entries may be present.
     @param filter Points to a CMPISelectExp object containing the
         filter specification defined by the indication filter that is being
         suthorized.
     @param className Points to a string specifying the class name extracted
         from the FROM clause of the filter specification contained in the
         filter argument. If the filter specification contains joins, it
         is undefined which of the joined classes is used for this argument.
     @param classPath Points to a CMPIObjectPath object that is a reference
         to a class or to a namespace, as follows:
            @li If the filter specification covers lifecycle
            indications, the CMPIObjectPath object specifies the
            class path of the class for which lifecycle monitoring
            is required. Note that this class may be a subclass of
            the class specified in @p className, for
            example when the filter query constrains the class to be
            monitored using constructs such as the ISA operator of
            CQL.
            @li If the filter specification covers process
            indications, the CMPIObjectPath object specifies the
            namespace path of the origin namespace of the process
            indications.
     @param owner @p owner points to a string
         specifying the destination owner.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful, filter is supported.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Operation not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx, @p filter, or @p classPath
         handles are invalid.
     @li `CMPI_RC_ERR_INVALID_QUERY` - Invalid query or too complex.

     @deprecated @p owner is deprecated since CMPI 2.1.
         MBs may pass an empty string in @p owner. For
         compatibility reasons, MBs shall not pass a NULL pointer
         in @p owner.
    */
    CMPIStatus (*authorizeFilter) (CMPIIndicationMI* mi,
        const CMPIContext* ctx, const CMPISelectExp* filter,
        const char* className, const CMPIObjectPath* classPath,
        const char* owner);

    /**
     @brief Ask the MI whether indication polling should be used
         for an indication filter. (**Deprecated**)

     CMPIIndicationMIFT.mustPoll() asks the MI whether polling mode
     should be used.

     This function enables very simple MIs to support indications without
     providing a complete indication support implementation. When true
     is returned, the MB will enumerate the instances of this MI at
     regular intervals and apply indication filters.

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param className The class name extracted from the filter FROM clause.
     @param filter The name of the class for which monitoring is required.
         Only the namespace part is set if eventType is a process indication.
     @param classPath The name of the class for which polling would be used.
         Only the namespace part is set if  className is a process indication.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Operation not supported by
         this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_QUERY` - Invalid query or too complex.

     @deprecated This function is deprecated since CMPI 2.1,
         because the concept of indication polling has been deprecated in
         CMPI 2.1.
    */
    CMPIStatus (*mustPoll) (CMPIIndicationMI* mi, const CMPIContext* ctx,
        const CMPISelectExp* filter, const char* className,
        const CMPIObjectPath* classPath);

    /**
     @brief Informs the MI that an indication filter has become active.

     CMPIIndicationMIFT.activateFilter() informs the MI
     that the specified indication filter has become active. This function
     shall be called by the MB when:
     @li a client creates a subscription to an indication filter
     @li if persisted subscriptions are supported
     by the MB, for any persisted subscriptions to indication filters
     when the MB starts up.

     An MB implementation is free to choose whether this function
     is called upon each subscription to a particular filter, or only upon
     the first subscription (see @p firstActivation). As a
     result, the MI will always be informed about the first activation of the
     filter after having been inactive, but has no guarantee to be informed
     about subsequent activations of the same filter.

     Generally, MIs should disable the monitoring of any resources for
     indications if there is no interest in them. Consequently, in this
     function the MI needs to start the monitoring of any resources that
     trigger indications that are covered by the specified indication
     filter, during the first activation of the filter. For the concept
     of coverage of indications by an indication filter, see
     @ref ref-dmtf-dsp1054 "DSP1054".

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
     @param filter Points to a CMPISelectExp object containing the
         filter specification defined by the indication filter that is
         activated.
     @param className Points to a string specifying the class name
         extracted from the FROM clause of the filter specification contained
         in @p filter. If the filter specification contains
         joins, it is undefined which of the joined classes is used for this
         argument.
     @param classPath Points to a CMPIObjectPath object that is a
         reference to a class or to a namespace, as follows:
            @li If the filter specification covers lifecycle
            indications, the CMPIObjectPath object specifies the
            class path of the class for which lifecycle monitoring
            is required. Note that this class may be a subclass of
            the class specified in the `>className` argument, for
            example when the filter query constrains the class to be
            monitored using constructs such as the `ISA` operator of
            CQL.
            @li If the filter specification covers process
            indications, the CMPIObjectPath object specifies the
            namespace path of the origin namespace of the process
            indications.
     @param firstActivation Set to true if this is the first activation of this
     indication filter after having been inactive, and is set to false
     otherwise.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Operation Function or filter
         is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized. Note: This
         return code indicates general authorization related issues
         and does not specifically indicate that the filter itself
         would not be authorized.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx, @p filter, or @p classPath
         handles are invalid.
     @li `CMPI_RC_ERR_INVALID_QUERY` - Invalid query or too complex.
    */
    CMPIStatus (*activateFilter) (CMPIIndicationMI* mi,
        const CMPIContext* ctx, const CMPISelectExp* filter,
        const char* className, const CMPIObjectPath* classPath,
        CMPIBoolean firstActivation);

    /**
     @brief Inform the MI that an indication filter has become inactive.

     CMPIIndicationMIFT.deActivateFilter() informs the MI that monitoring
     using this filter should stop.
     This function shall be called by the MB when a client deletes a
     subscription to an indication filter, and for any existing
     subscriptions to indication filters when the MB shuts down.

     The function invocation mandates the MI to stop monitoring the resource
     using this filter.

     An MB implementation is free to choose whether this function is called
     for each deletion of a subscription to a particular filter, or
     only upon the last deletion (see @p lastDeActivation).
     As a result, the MI will always be informed about the last
     deactivation of the filter, but has no guarantee to be informed
     about prior deactivations of the same filter.

     Generally, MIs should disable the monitoring of any resources for
     indications if there is no interest in them. Consequently, in this
     function the MI should stop the monitoring of any resources that
     trigger indications that are covered by the specified indication
     filter, during the last deactivation of the filter. For the concept
     of coverage of indications by an indication filter, see
     @ref ref-dmtf-dsp1054 "DSP1054".

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         If the filter is deactivated because a client deletes a subscription
         to the filter, the client operation that deletes the subscription
         determines the context data.
         If the filter is deactivated during MB shutdown, the client operation
         that originally created the subscription determines the context data
     @param filter Points to a CMPISelectExp object containing the
         filter specification defined by the indication filter that is
         deactivated.
     @param className Points to a string specifying the class name extracted
        from the FROM clause of the filter specification contained in the
        @p filter argument. If the filter specification contains joins,
        it is undefined which of the joined classes is used for this argument.
     @param classPath Points to a CMPIObjectPath object is a reference to
         a class or to a namespace, as follows:
            @li If the filter specification covers lifecycle
            indications, the CMPIObjectPath object specifies the
            class path of the class for which lifecycle monitoring
            is required.  Note that this class may be a subclass of
            the class specified in @p className, for
            example when the filter query constrains the class to be
            monitored using constructs such as the ISA operator of
            CQL.
            @li If the filter specification covers process
            indications, the CMPIObjectPath object specifies the
            namespace path of the origin namespace of the process
            indications
     @param lastActiviation Set to true if this is the last filter for
         @p className.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Operation not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx, @p filter, or @p classPath
         handles are invalid.
     @li `CMPI_RC_ERR_INVALID_QUERY` - Invalid query or too complex.

     @todo TBD KS: We set first activation if this is first for
           filter and lastActivation if last for className (not
           filter)
    */
    CMPIStatus (*deActivateFilter) (CMPIIndicationMI* mi,
        const CMPIContext* ctx, const CMPISelectExp* filter,
        const char* className, const CMPIObjectPath* classPath,
        CMPIBoolean lastDeActiviation);

    /**
     @brief Inform the MI that the MB is now ready to process the delivery of
         indications.

     CMPIIndicationMIFT.enableIndications() informs the MI that the MB
     is now ready to process the delivery of
     indications. This function is typically called when the MB is starting
     up its indication services (from either a permanent or temporary
     shutdown of its indication services).

     The relative order in which an MB enables indications using this
     function and activates filters and filter collections is not defined.
     As a result, MIs need to track the readiness of the MB to process
     the delivery of indications and check that readiness before calling
     @ref CMPIBrokerFT::deliverIndication
     "CMPIBrokerFT.deliverIndication()".

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         There is no defined client operation that determines the context data.
         As a result, not all context data entries may be present.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Operation not supported by
         this MI.
    */
    CMPIStatus (*enableIndications) (CMPIIndicationMI* mi,
        const CMPIContext* ctx);

    /**
     @brief Inform the MI that the MB is no longer ready to
         process the delivery of indications.

     CMPIIndicationMIFT.disableIndications() informs the MI that the MB
     is no longer ready to process the delivery of
     indications.  This function is typically called when the MB is shutting
     down its indication services either temporarily or permanently.

     The relative order in which an MB disables indications using this
     function and deactivates filters and filter collections is not
     defined. As a result, MIs need to track the readiness of the MB
     to process the delivery of indications and check that readiness
     before calling @ref CMPIBrokerFT::deliverIndication
     "CMPIBrokerFT.deliverIndication()".

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         There is no defined client operation that determines the context data.
         As a result, not all context data entries may be present.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Operation not supported by
         this MI.
    */
    CMPIStatus (*disableIndications) (CMPIIndicationMI* mi,
        const CMPIContext* ctx);

    /**
     @brief Ask an MI to verify whether an indication filter
         collection is supported by the MI.

     CMPIIndicationMIFT.authorizeFilterCollection() shall verify whether an
     indication filter collection is supported by the MI.

     An MB implementation is free to choose whether this function
     is called when the MB starts up independently of whether or not
     there are any subscriptions for the filter collection, or only
     when the first subscription to the filter collection is made.

     In any case, for any particular filter collection this function
     is called on, it shall be called by the MB before
     CMPIIndicationMIFT.activateFilterCollection() is called for the
     first time on the same filter collection.

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         There is no defined client operation that determines the context data.
         As a result, not all context data entries may be present.
     @param collInst Points to a CMPIInstance object with the
         CIM_FilterCollection instance representing the indication
         filter collection. Note that the indication filter collection
         can be identified by inspecting the CollectionName property
         of this instance
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful, filter collection is supported
         by the MI.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI, or
         filter collection is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
         Note: This return code indicates general authorization related
         issues and does not specifically indicate that the filter
         collection itself would not be authorized.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx or @p collInst handles are
         invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - Invalid indication filter
         collection.

     @added210 Added in CMPI 2.1.0.
    */
    CMPIStatus (*authorizeFilterCollection) (CMPIIndicationMI* mi,
        const CMPIContext* ctx, const CMPIInstance* collInst);

    /**
     @brief Inform the MI that an indication filter collection
         has become active.

     CMPIIndicationMIFT.activateFilterCollection() informs the
     MI that the specified indication filter collection has become active.
     This function shall be called by the MB when a client creates a
     subscription to an indication filter collection, and if persisted
     subscriptions are supported by the MB, for any persisted subscriptions
     to indication filter collections when the MB starts up.

     An MB implementation is free to choose whether this function is
     called upon each subscription to a particular filter collection, or
     only upon the first subscription (see the @p firstActivation
     argument).

     As a result, the MI will always be informed about the first
     activation of the filter collection, but has no guarantee to be
     informed about subsequent activations of the same filter collection.

     Generally, MIs should disable the monitoring of any resources for
     indications if there is no interest in them. Consequently, in this
     function the MI needs to start the monitoring of any resources that
     trigger indications that are covered by the specified indication
     filter collection, during the first activation of the filter
     collection. For the concept of coverage of indications by an
     indication filter collection, see @ref ref-dmtf-dsp1054 "DSP1054".

     As described in DSP1054, a filter collection conceptually has
     members, but these members do not need to be instantiated using
     CIM. An MB shall handle subscriptions to a filter collection by
     calling CMPIIndicationMIFT.activateFilterCollection() for that
     filter collection; the MB shall not additionally call the activation
     functions for the individual members of the filter collection.
     The implementation of CMPIIndicationMIFT.activateFilterCollection()
     is responsible for activating the entire filter collection including
     all of its members (regardless of whether or not these members are
     instantiated using CIM).

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         If the filter
         collection is activated because a client creates a
         subscription to the filter collection, the client operation
         that creates the subscription determines the context data.
         If the filter collection is activated during MB startup on
         behalf of a persisted earlier subscription, the client operation
         that originally created the subscription determines the context
         data.
     @param collInst Points to a CMPIInstance object with the
         CIM_FilterCollection instance representing the indication
         filter collection. Note that the indication filter collection
         can be identified by inspecting the CollectionName property
         of this instance.
     @param firstActivation set to true if this is the first activation
         of this indication filter collection after having been inactive,
         and is set to false otherwise
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not
         supported by this MI, or filter collection is not
         supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized.
         Note: This return code indicates general authorization related issues
         and does not specifically indicate that the filter collection
         itself would not be authorized.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx or @p collInst handles are
         invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - Invalid indication filter collection.

     @added210 Added in CMPI 2.1.0.
    */
    CMPIStatus (*activateFilterCollection) (CMPIIndicationMI* mi,
        const CMPIContext* ctx, const CMPIInstance* collInst,
        CMPIBoolean firstActivation);

    /**
     @brief Informs the MI that an indication filter collection
         has become inactive.

     CMPIIndicationMIFT.deActivateFilterCollection() informs
     the MI that the specified indication filter collection has become
     inactive. This function shall be called by the MB when a client
     deletes a subscription to an indication filter collection, and for
     any existing subscriptions to indication filter collections when
     the MB shuts down.

     This function is called either when a client deletes a subscription
     to an indication filter collection, or when the MB shuts down
     and deactivates a subscription.

     An MB implementation is free to choose whether this function is
     called upon each deletion of a subscription to a particular
     filter collection, or only upon the last deletion
     (see @p lastDeActivation). As a result, the MI will
     always be informed about the last deactivation of the filter
     collection, but has no guarantee to be informed about prior
     deactivations of the same filter collection.

     Generally, MIs should disable the monitoring of any resources for
     indications if there is no interest in them. Consequently, in this
     function the MI should stop the monitoring of any resources that
     trigger indications that are covered by the specified indication
     filter collection, during the last deactivation of the filter. For
     the concept of coverage of indications by an indication filter
     collection, see @ref ref-dmtf-dsp1054 "DSP1054".

     As described in DSP1054, a filter collection conceptually has
     members, but these members do not need to be instantiated using CIM.
     An MB shall handle deletions to subscriptions to a filter collection
     by calling CMPIIndicationMIFT.deActivateFilterCollection() for that
     filter collection; the MB shall not additionally call the deactivation
     functions for the individual members of the filter collection.
     The implementation of CMPIIndicationMIFT.deActivateFilterCollection()
     is responsible for deactivating the entire filter collection including
     all of its members (regardless of whether or not these members are
     instantiated using CIM).

     @param mi Points to a CMPIIndicationMI structure.
     @param ctx Points to a CMPIContext object containing the context data
         for the invocation.
         If the filter
         collection is activated because a client creates a
         subscription to the filter collection, the client operation
         that creates the subscription determines the context data.
         If the filter collection is activated during MB startup on
         behalf of a persisted earlier subscription, the client operation
         that originally created the subscription determines the context
         data.
     @param collInst Points to a CMPIInstance object with the
         CIM_FilterCollection instance representing the indication
         filter collection. Note that the indication filter collection
         can be identified by inspecting the CollectionName property
         of this instance.
     @param lastDeactivation set to true if this is the last deactivation
         of this indication filter collection after having been active;
         set to false otherwise.
     @return CMPIStatus structure containing the function return status.

     @par Errors
     The function return status will indicate one of the following @ref CMPIrc
     codes:
     @li `CMPI_RC_OK` - Function successful.
     @li `CMPI_RC_ERR_FAILED` - Other error occurred.
     @li `CMPI_RC_ERR_NOT_SUPPORTED` - Function is not supported by this MI, or
         filter collection is not supported by this MI.
     @li `CMPI_RC_ERR_ACCESS_DENIED` - Not authorized. Note: This
         return code indicates general authorization related issues and
         does not specifically indicate that the filter collection itself
         would not be authorized.
     @li `CMPI_RC_ERR_INVALID_HANDLE` - The @p ctx or @p collInst handles are
         invalid.
     @li `CMPI_RC_ERR_INVALID_PARAMETER` - Invalid indication filter collection.

     @added210 Added in CMPI 2.1.0.
    */
    CMPIStatus (*deActivateFilterCollection) (CMPIIndicationMI* mi,
        const CMPIContext* ctx, const CMPIInstance* collInst,
        CMPIBoolean lastDeActivation);

} CMPIIndicationMIFT;

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /*_CMPIFT_H_ */
